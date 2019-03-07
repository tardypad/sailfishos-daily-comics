/**
 * Copyright (c) 2018-2019 Oleg Linkin <maledictusdemagog@gmail.com>
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

Item {
    id: overlay

    property bool active: true
    property bool viewerOnlyMode

    property alias toolbar: toolbar
    readonly property bool allowed: true
    property real fadeOpacity: 0.6

    property var comicProxy: null
    property var comicIndex
    property ComicsModel comicsModel


    property string itemId
    property bool error


    enabled: active && allowed && comicProxy !== null
    Behavior on opacity { FadeAnimator {}}
    opacity: enabled ? 1.0 : 0.0

    Rectangle {
        id: bottomFade
        width: parent.width
        height: toolbar.height + 2* toolbar.anchors.bottomMargin
        anchors.bottom: parent.bottom
        gradient: Gradient {
            GradientStop { position: 0.0; color: "transparent" }
            GradientStop { position: 0.8; color: Qt.rgba(0, 0, 0, fadeOpacity) }
            GradientStop { position: 1.0; color: Qt.rgba(0, 0, 0, fadeOpacity) }
        }
    }

    Row {
        id: toolbar

        x: parent.width/2 - width/2
        anchors  {
            bottom: parent.bottom
            bottomMargin: Theme.paddingLarge
        }
        spacing: Theme.paddingLarge

        IconButton {
            id: infoButton
            icon.source: "image://theme/icon-m-about"
            anchors.verticalCenter: parent.verticalCenter
            enabled: comicProxy
            onClicked: {
                pageStack.push("../pages/ComicInfoPage.qml",
                        { index: comicIndex, model: comicsModel })
            }
        }

        IconButton {
            id: saveToGalleryButton
            icon.source: "image://theme/icon-m-cloud-download"
            anchors.verticalCenter: parent.verticalCenter
            enabled: !comicProxy ? false : comicProxy.stripImageDownloaded
            onClicked: {
                window.notify(comicProxy.saveToGallery() ?
                        qsTr("Comic strip was saved to gallery") :
                        qsTr("Unable to save comic strip to gallery"))
            }
        }

        IconButton {
            id: clipboardButton
            icon.source: "image://theme/icon-m-clipboard"
            anchors.verticalCenter: parent.verticalCenter
            enabled: comicProxy
            onClicked: {
                Clipboard.text = comicProxy.stripImageUrl
                window.notify(Clipboard.text !== "" ?
                        qsTr("Comic strip url copied to clipboard") :
                        qsTr("Unable to copy comic strip url to clipboard"))
            }
        }

        IconButton {
            id: shareButton
            icon.source: "image://theme/icon-m-share"
            anchors.verticalCenter: parent.verticalCenter
            enabled: comicProxy
            onClicked: {
                pageStack.push(Qt.resolvedUrl("../pages/ShareLinkPage.qml"),
                        {
                           "link": comicProxy.stripImageUrl.toString(),
                           "linkTitle": comicProxy.name
                        })
            }
        }

        IconButton {
            id: browserButton
            icon.source: "image://theme/icon-m-region"
            anchors.verticalCenter: parent.verticalCenter
            enabled: comicProxy
            onClicked: Qt.openUrlExternally(encodeURI(comicProxy.homepage))
        }
    }
}

