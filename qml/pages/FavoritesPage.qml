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
import "../utils"

Page {

    allowedOrientations: Orientation.All

    SilicaGridView {
        id: gridView

        property int cellSize: isPortrait
                               ? (favoriteComicsModel.count > 8 ? parent.width / 3 : parent.width / 2)
                               : (favoriteComicsModel.count > 8 ? parent.width / 5 : parent.width / 4)
        anchors.fill: parent
        cellWidth: cellSize
        cellHeight: cellSize
        header: PageHeader {
            title: "Daily Comics"
        }
        delegate: ComicsGridDelegate { }
        model: comicsModelProxy

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
                text: favoriteComicsModel.newCount > 0 ? "Read all new comics" : "No new comic"
                onClicked: pageStack.push(Qt.resolvedUrl("NewComicsPage.qml"), {"comicsModel": favoriteComicsModel})
                enabled: favoriteComicsModel.newCount > 0
                visible: favoriteComicsModel.count > 0
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
            pageStack.push(Qt.resolvedUrl("ComicPage.qml"), {
                               "index": comicsModelProxy.sourceRow(index),
                               "comicsModel": favoriteComicsModel
                           })
        }
    }

    ProgressInfoBar {
        label: "Fetching comic strips"
        open: favoriteComicsModel.fetchedCount < favoriteComicsModel.count
        minimumValue: 0
        maximumValue: favoriteComicsModel.count
        value: favoriteComicsModel.fetchedCount

        anchors.bottom: parent.bottom
    }

    FavoriteComicsModel {
        id: favoriteComicsModel
        Component.onCompleted: {
            favoriteComicsModel.loadAll()
            favoriteComicsModel.fetchAll()
        }
    }

    ComicsModelProxy {
        id: comicsModelProxy
        comicsModel: favoriteComicsModel
        sortRole: ComicsModel.NameRole
    }

    Connections {
        target: favoriteComicsModel
        onFavoritesChanged: {
            favoriteComicsModel.loadAll()
            favoriteComicsModel.fetchAll()
        }
    }

    Timer {
        running: true
        repeat: true
        interval: 3600000
        onTriggered: favoriteComicsModel.fetchAll()
    }

    Connections {
        target: window
        onApplicationActiveChanged: {
            if (applicationActive) {
                favoriteComicsModel.fetchAll()
            }
        }
    }

}
