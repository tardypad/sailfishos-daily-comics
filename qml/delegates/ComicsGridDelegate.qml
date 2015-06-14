/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "../components/"

Item {
    id: itemcontainer

    property int idx: index
    property bool down: comicItem.pressed && comicItem.containsMouse

    property bool _hasContextMenu: gridView.contextMenu && gridView.contextMenu.parent === itemcontainer

    width: gridView.cellWidth
    height: _hasContextMenu
            ? gridView.cellHeight + gridView.contextMenu.height
            : gridView.cellHeight

    opacity: !_hasContextMenu && gridView.contextMenuActive ? 0.2 : 1

    BackgroundItem {
        id: comicItem

        width: gridView.cellWidth
        height: gridView.cellHeight
        y: gridView.contextMenu && index >= gridView.minOffsetIndex
           ? gridView.contextMenu.height
           : 0

        highlighted: down || _hasContextMenu

        Image {
            source: Qt.resolvedUrl("../../images/comics/covers/"+id+".jpg")
            anchors.fill: parent
            sourceSize.width: Screen.width / 2
            sourceSize.height: Screen.width / 2
        }

        StatusRectangle {
            mainColor: idColor
            hasNew: newStrip
            hasError: error
            isFetching: fetching
            fetchingProgressValue: fetchingProgress

            anchors {
                right: parent.right
                bottom: parent.bottom
            }
        }

        onPressAndHold: gridView._showContextMenu(itemcontainer)

        onClicked: gridView._goToComicPage(index)

        onPressed: gridView.currentIndex = index
    }

    GridView.onRemove: RemoveAnimation {
        target: itemcontainer
        duration: 700
    }
}
