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
        anchors.fill: parent
        source: Qt.resolvedUrl("../../images/comics/covers/"+id+".jpg")
    }

    Rectangle {
        property bool active: favorite

        anchors.fill: parent
        color: Theme.highlightBackgroundColor
        opacity: active ? 0.7 : 0.0

        Image {
            source: "image://theme/icon-l-favorite"
            height: Theme.iconSizeSmall
            width: Theme.iconSizeSmall
            anchors {
                left: parent.left
                top: parent.top
                leftMargin: Theme.paddingSmall
                topMargin: Theme.paddingSmall
            }
            fillMode: Image.PreserveAspectFit
        }

        Behavior on opacity {
            FadeAnimation {
                duration: 100
            }
        }
    }

    onClicked: comicsModel.setFavorite(index, !favorite)

    onPressAndHold: gridView._showComicInfo(index)
}
