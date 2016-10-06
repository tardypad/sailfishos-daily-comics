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

        property int cellNumberPerRow: Screen.sizeCategory >= Screen.Large
                                       ? (isPortrait ? 3 : 5)
                                       : (isPortrait ? 2 : 4)

        property int cellNumberPerRowFav: favoriteComicsModel.count >= cellNumberPerRow * 4
                                          ? cellNumberPerRow + 1
                                          : cellNumberPerRow

        property int cellSize: parent.width / cellNumberPerRowFav

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
            busy: favoriteComicsModel.newCount > 0 && !progressInfoBar.open

            MenuItem {
                text: qsTr("Settings")
                onClicked: pageStack.push(Qt.resolvedUrl("ComicsSettingsPage.qml"))
            }
            MenuItem {
                text: qsTr("Report problems with comics")
                onClicked: {
                    var comicsNamesList = favoriteComicsModel.errorComicNames();
                    var encodedComicsNamesList = [];
                    for (var i = 0; i < comicsNamesList.length; i++) {
                        encodedComicsNamesList.push(encodeURIComponent(comicsNamesList[i]))
                    }
                    var finalComicsList = "\"" + encodedComicsNamesList.join("\", \"") + "\""
                    ExternalLinks.mail(constants.devMail, constants.mailErrorSubjectHeader,
                                              constants.mailBodyHeader + "There are problems with comics: " + finalComicsList)
                }
                visible: favoriteComicsModel.errorCount > 0
            }
            MenuItem {
                text: favoriteComicsModel.newCount > 0 ? qsTr("Read all new comics") : qsTr("No new comic")
                onClicked: pageStack.push(Qt.resolvedUrl("NewComicsPage.qml"), {"comicsModel": favoriteComicsModel})
                enabled: favoriteComicsModel.newCount > 0
                visible: favoriteComicsModel.count > 0
            }
        }

        PushUpMenu {
            spacing: Theme.paddingLarge

            MenuItem {
                text: qsTr("About")
                onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
            }
        }

        ViewPlaceholder {
            enabled: gridView.count == 0
            text: qsTr("No comic selected")
            hintText: qsTr("Choose your favorite comics in the settings page")
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
                    text: qsTr("Remove from favorites")
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
        id: progressInfoBar
        label: qsTr("Fetching comic strips")
        open: favoriteComicsModel.fetchedCount < favoriteComicsModel.count
        newCount: favoriteComicsModel.newCount
        errorCount: favoriteComicsModel.errorCount
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
            favoriteComicsModel.startAutomaticFetch(3600000) // 1H
        }
    }

    ComicsModelProxy {
        id: comicsModelProxy
        comicsModel: favoriteComicsModel
        sortRole: ComicsModel.SortNameRole
    }

    Connections {
        target: favoriteComicsModel
        onFavoritesChanged: {
            favoriteComicsModel.loadAll()
            favoriteComicsModel.fetchAll()
        }
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
