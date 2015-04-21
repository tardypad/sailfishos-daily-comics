/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import harbour.dailycomics.Comics 1.0

import "../utils"

Page {
    id: comicPage

    allowedOrientations: Orientation.All

    property int index
    property ComicsModel comicsModel

    ComicProxy {
        id: comic
    }

    SilicaFlickable {
        id: comicView

        anchors.fill: parent

        Image {
            source: !comic.error && !indicator.busy ? comic.stripUrl : ''
            fillMode: Image.PreserveAspectFit
            smooth: true
            clip: true
            asynchronous: true
            anchors.fill: parent

            BusyIndicator {
                running: parent.status === Image.Loading
                size: BusyIndicatorSize.Large
                anchors.centerIn: parent
            }

            onStatusChanged: {
                if (status === Image.Ready)
                    comic.read()
            }
        }

        LoadingIndicator {
            id: indicator
            model: comic
            flickable: comicView
            loadingText: "Loading comic"
            defaultErrorText: "Can't display comic"
            networkErrorText: "Can't download comic"
            parsingErrorText: "Can't extract comic"
            devContactErrorMessage: "There is a problem with comic \"" + comic.name + "\""
        }

        PullDownMenu {
            MenuItem {
                text: "Show comic info"
                onClicked: comicView._showComicInfo()
            }
        }

        function _showComicInfo() {
            if (infoPanelLoader.status === Loader.Null) {
                infoPanelLoader.source = Qt.resolvedUrl("../components/ComicInfoPanel.qml")
                infoPanelLoader.item.parent = comicPage
                infoPanelLoader.item.index = index
                infoPanelLoader.item.comicsModel = comicsModel
            }
            infoPanelLoader.item.showComicInfo()
        }
    }

    Loader {
        id: infoPanelLoader
    }

    onStatusChanged: {
        if (status === PageStatus.Inactive)
            comic.abortFetching()
    }

    Component.onCompleted: {
        comic.setComic(comicsModel.comicAt(index))
        comic.fetch()
    }
}
