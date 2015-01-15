/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "../components/"

BackgroundItem {
    width: gridView.cellWidth
    height: gridView.cellHeight

    Image {
        source: Qt.resolvedUrl("../../images/comics/covers/"+id+".jpg")
        anchors.fill: parent
    }

    StatusRectangle {
        color: Qt.darker(idColor, 1.1)
        hasNew: newStrip
        hasError: error

        anchors {
            right: parent.right
            bottom: parent.bottom
        }
    }

    onClicked: gridView._goToComicPage(id)

    onPressed: gridView.currentIndex = index
}
