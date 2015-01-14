/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

BackgroundItem {
    width: gridView.cellWidth
    height: gridView.cellHeight

    Image {
        source: Qt.resolvedUrl("../../images/comics/covers/"+id+".jpg")
        anchors.fill: parent
    }

    Rectangle {
        opacity: newStrip ? 1.0 : 0.0
        color: Qt.darker(idColor, 1.1)
        anchors {
            right: parent.right
            bottom: parent.bottom
        }
        width: newImage.width + newLabel.width + 3*Theme.paddingSmall
        height: newImage.height + 2*Theme.paddingSmall

        Image {
            id: newImage
            anchors {
                left: parent.left
                leftMargin: Theme.paddingSmall
                bottom: parent.bottom
                bottomMargin: Theme.paddingSmall
            }
            source: "image://theme/icon-s-update"
            height: Theme.iconSizeSmall
            width: Theme.iconSizeSmall
            fillMode: Image.PreserveAspectFit
        }

        Label {
            id: newLabel
            anchors {
                left: newImage.right
                leftMargin: Theme.paddingSmall
                bottom: parent.bottom
                bottomMargin: Theme.paddingSmall
            }
            text: "New"
            font.pixelSize: Theme.fontSizeExtraSmall
        }

    }


    onClicked: gridView._goToComicPage(id)

    onPressed: gridView.currentIndex = index
}
