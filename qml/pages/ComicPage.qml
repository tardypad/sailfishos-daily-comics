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
import "../components"

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
        contentWidth: width
        contentHeight: Math.max(comicImage.height + 2*Theme.paddingLarge, parent.height)

        BusyIndicator {
            running: comicImage.status === Image.Loading
            size: BusyIndicatorSize.Large
            x: (comicPage.width - width) / 2
            y: (comicPage.height - height) / 2
        }

        ComicImage {
            id: comicImage
            animated: comic.animated
            source: !comic.error && !indicator.busy ? comic.stripImagePath : ''

            anchors.centerIn: parent
            width: parent.width
            height: (implicitHeight / implicitWidth ) * width

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
        }

        ErrorContactDevRectangle {
            comicName: comic.name
            flickable: comicView
            active: indicator.error
            z: 10
        }

        PullDownMenu {
            MenuItem {
                visible: !indicator.busy
                text: "Report a problem with the comic"
                onClicked: ExternalLinks.mail(constants.devMail, constants.mailErrorSubjectHeader,
                                              constants.mailBodyHeader + "There is a problem with comic \"" + encodeURIComponent(comic.name) + "\"")
            }
            MenuItem {
                text: "Copy url to clipboard"
                onClicked: Clipboard.text = comic.stripImageUrl
            }
            MenuItem {
                text: "Show comic info"
                onClicked: comicView._showComicInfo()
            }
            MenuItem {
                text: "Go to homepage"
                onClicked: ExternalLinks.browse(comic.homepage)
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
