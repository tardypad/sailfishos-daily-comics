/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import harbour.dailycomics.Comics 1.0

import "../delegates"

Page {

    allowedOrientations: Orientation.All

    SilicaGridView {
        id: gridView

        property int cellSize: isPortrait ? parent.width / 2 : parent.width / 4

        anchors.fill: parent
        cellWidth: cellSize
        cellHeight: cellSize
        header: PageHeader {
            title: "Daily Comics"
        }
        delegate: ComicsGridDelegate { }
        model: comicsModel

        Rectangle {
            property bool active: gridView.currentItem && gridView.currentItem.down
            width: gridView.cellWidth
            height: gridView.cellHeight
            color: Theme.highlightBackgroundColor
            opacity: active ? 0.5 : 0
            x: gridView.currentItem != null ? gridView.currentItem.x : 0
            y: gridView.currentItem != null ? gridView.currentItem.y - gridView.contentY : 0
            z: gridView.currentItem != null ? gridView.currentItem.z + 1 : 0
        }

        PullDownMenu {
            MenuItem {
                text: "Settings"
                onClicked: pageStack.push(Qt.resolvedUrl("ComicsSettingsPage.qml"))
            }
            MenuItem {
                text: comicsModel.newCount > 0 ? "Read all new comics" : "No new comic"
                onClicked: pageStack.push(Qt.resolvedUrl("NewComicsPage.qml"), {"comicsModel": comicsModel})
                enabled: comicsModel.newCount > 0
            }
        }

        PushUpMenu {
            MenuItem {
                text: "About"
                onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
            }
        }

        ViewPlaceholder {
            enabled: gridView.count == 0
            text: "No comic selected"
            hintText: "Choose your favorite comics in the settings page"
        }

        VerticalScrollDecorator { flickable: gridView }

        function _goToComicPage(index) {
            pageStack.push(Qt.resolvedUrl("ComicPage.qml"), {"index": index, "comicsModel": comicsModel})
        }
    }

    FavoriteComicsModel {
        id: comicsModel
        Component.onCompleted: {
            comicsModel.loadAll()
            comicsModel.fetchAll()
        }
    }

    Connections {
        target: comicsModel
        onFavoritesChanged: {
            comicsModel.loadAll()
            comicsModel.fetchAll()
        }
    }

}


