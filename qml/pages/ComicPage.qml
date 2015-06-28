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

import "../scripts/ExternalLinks.js" as ExternalLinks

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

        AnimatedImage {
            source: !comic.error && !indicator.busy ? comic.stripImagePath : ''
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
                else if (status === Image.Error) {
                    indicator.displayError("Image error", "Can't display strip")
                    comic.setError()
                }
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
            savingErrorText: "Can't save comic"
            mailErrorMail: constants.devMail
            mailErrorSubject: constants.mailErrorSubjectHeader
            mailErrorMessage: constants.mailBodyHeader + "There is a problem with comic \"" + encodeURIComponent(comic.name) + "\""
        }

        PullDownMenu {
            MenuItem {
                text: "Show comic info"
                onClicked: comicView._showComicInfo()
            }
            MenuItem {
                text: "Go to homepage"
                onClicked: ExternalLinks.browse(comic.homepage)
            }
        }

        PushUpMenu {
            visible: !indicator.busy

            MenuItem {
                text: "Report a problem with the comic"
                onClicked: ExternalLinks.mail(constants.devMail, constants.mailErrorSubjectHeader,
                                              constants.mailBodyHeader + "There is a problem with comic \"" + encodeURIComponent(comic.name) + "\"")
            }
        }

        function _showComicInfo() {
            if (infoPanelLoader.status === Loader.Null) {
                infoPanelLoader.source = Qt.resolvedUrl("../components/ComicInfoPanel.qml")
                infoPanelLoader.item.parent = comicPage
                infoPanelLoader.item.index = index
                infoPanelLoader.item.comicsModel = comicsModel
                infoPanelLoader.item.homepageMenu = false
            }
            infoPanelLoader.item.showComicInfo()
        }
    }

    Loader {
        id: infoPanelLoader
    }

    Component.onCompleted: {
        comic.setComic(comicsModel.comicAt(index))
        comic.fetch()
    }
}
