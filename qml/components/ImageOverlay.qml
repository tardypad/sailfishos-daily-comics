/**
 * Copyright (c) 2018 Oleg Linkin
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

    property var comicProxy
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
            icon.source: "image://Theme/icon-m-about"
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                pageStack.push("../pages/ComicInfoPage.qml",
                        { index: comicIndex, model: comicsModel })
            }
        }

        IconButton {
            id: problemButton
            icon.source: "image://Theme/icon-m-mail"
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                ExternalLinks.mail(constants.devMail, constants.mailErrorSubjectHeader,
                        constants.mailBodyHeader + "There is a problem with comic \"" +
                                encodeURIComponent(comicProxy.name) + "\"")
            }
        }

        IconButton {
            id: clipboardButton
            icon.source: "image://Theme/icon-m-clipboard"
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                Clipboard.text = comicProxy.stripImageUrl
            }
        }

        IconButton {
            id: shareButton
            icon.source: "image://Theme/icon-m-share"
            anchors.verticalCenter: parent.verticalCenter
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
            icon.source: "image://Theme/icon-m-region"
            anchors.verticalCenter: parent.verticalCenter
            onClicked: {
                Qt.openUrlExternally(encodeURI(comicProxy.homepage))
            }
        }
    }
}

