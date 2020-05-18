/**
 * Copyright (c) 2018-2019 Oleg Linkin <maledictusdemagog@gmail.com>
 * Copyright (c) 2020 Mirian Margiani
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

ZoomableImage {
    id: zoomableImage
    imageOpacity: indicator.visible ? Theme.opacityLow : 1.0

    property alias comicProxy: indicator.model
    property alias indicator: indicator

    ready: imagePath !== "" && !indicator.busy

    StatusOverlay {
        id: indicator
        loadingText: qsTr("Loading comic")
        defaultErrorText: qsTr("Can't display comic")
        networkErrorText: qsTr("Can't download comic")
        parsingErrorText: qsTr("Can't extract comic")
        savingErrorText: qsTr("Can't save comic")
    }

    MouseArea {
        anchors.fill: parent
        enabled: indicator.overlayVisible
        onClicked: {
            indicator.visible = !indicator.visible
            zoomableImage.active = !indicator.visible
        }
    }

    BackgroundItem {
        visible: indicator.error
        parent: zoomableImage
        anchors.bottom: parent.bottom
        width: parent.width
        height: Theme.itemSizeMedium

        onClicked: {
            ExternalLinks.mail(constants.maintainerMail, constants.mailErrorSubjectHeader,
                constants.mailBodyHeader + 'There is a problem with comic "%1"'.arg(encodeURIComponent(zoomableImage.name)))
        }

        Rectangle {
            anchors.fill: parent; z: -1
            visible: indicator.overlayVisible && !indicator.visible
            color: Theme.highlightDimmerColor
            opacity: Theme.opacityOverlay
        }

        Label {
            anchors {
                leftMargin: Theme.horizontalPageMargin; left: parent.left
                rightMargin: Theme.paddingMedium; right: mailButton.left
                top: parent.top; bottom: parent.bottom
            }
            verticalAlignment: Text.AlignVCenter
            text: qsTr("Please contact me if the problem persists.")
            font.pixelSize: Theme.fontSizeExtraSmall
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        }

        HighlightImage {
            id: mailButton
            anchors {
                right: parent.right; rightMargin: Theme.horizontalPageMargin
                verticalCenter: parent.verticalCenter
            }
            height: Theme.iconSizeMedium; width: height
            source: "image://theme/icon-m-mail"
            highlighted: parent.highlighted
        }
    }
}
