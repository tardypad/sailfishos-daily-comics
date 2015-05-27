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

import "../scripts/ExternalLinks.js" as ExternalLinks

Page {
    objectName: "FavoritesPage"

    allowedOrientations: Orientation.All

    property ComicsModel comicsModel: favoriteComicsModel

    SilicaGridView {
        id: gridView

        property int cellNumberPerRow: isPortrait
                                       ? (favoriteComicsModel.count > 8 ? 3 : 2)
                                       : (favoriteComicsModel.count > 8 ? 5 : 4)
        property int cellSize: parent.width / cellNumberPerRow

        property Item contextMenu
        property int minOffsetIndex: contextMenu && contextMenu.parent
                                     ? contextMenu.parent.idx - (contextMenu.parent.idx % cellNumberPerRow) + cellNumberPerRow
                                     : 0
        property bool contextMenuActive: contextMenu && contextMenu.active

        anchors.fill: parent
        cellWidth: cellSize
        cellHeight: cellSize
        header: PageHeader {
            title: "Daily Comics"
        }
        delegate: ComicsGridDelegate { }
        model: comicsModelProxy

        Rectangle {
            property bool active: gridView.currentItem && gridView.currentItem.down && !gridView.contextMenuActive
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
                text: "Report problems with comics"
                onClicked: {
                    var comicsNamesList = "\"" + favoriteComicsModel.errorComicNames().join("\", \"") + "\""
                    ExternalLinks.mail(constants.devMail, constants.mailErrorSubjectHeader,
                                              constants.mailBodyHeader + "There are problems with comics: " + comicsNamesList)
                }
                visible: favoriteComicsModel.errorCount > 0
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

        function _showContextMenu(item) {
            if (!contextMenu)
                contextMenu = actionsComponent.createObject(gridView)
            contextMenu.show(item)
        }

        Component {
            id: actionsComponent
            ContextMenu {
                property Item delegate: parent
                property int index: delegate ? delegate.idx : -1

                width: gridView.width

                MenuItem {
                    text: "Remove from favorites"
                    onClicked: gridView._removeFavorite(index)
                }
            }
        }

        function _goToComicPage(index) {
            pageStack.push(Qt.resolvedUrl("ComicPage.qml"), {
                               "index": comicsModelProxy.sourceRow(index),
                               "comicsModel": favoriteComicsModel
                           })
        }

        function _removeFavorite(index) {
            favoriteComicsModel.removeFavorite(comicsModelProxy.sourceRow(index))
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
            window.cover.favoritesComicsModel = favoriteComicsModel
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
