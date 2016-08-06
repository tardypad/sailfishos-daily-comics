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
import "../components"

Page {
    id: comicPage

    allowedOrientations: Orientation.All

    SilicaGridView {
        id: gridView

        property int cellNumberPerRow: Screen.sizeCategory >= Screen.Large
                                       ? (isPortrait ? 4 : 6)
                                       : (isPortrait ? 3 : 5)

        property int cellSize: parent.width / cellNumberPerRow

        anchors.fill: parent
        cellWidth: cellSize
        cellHeight: cellSize
        header: PageHeader {
            title: "Select favorites"
        }
        delegate: ComicsSettingsGridDelegate { }
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
                text: "Clear all"
                onClicked: settingsComicsModel.unfavoriteAll()
                visible: settingsComicsModel.favoritesCount > 0

            }
            MenuItem {
                text: "Select all"
                onClicked: settingsComicsModel.favoriteAll()
                visible: settingsComicsModel.favoritesCount !== settingsComicsModel.count
            }
        }

        footer: RequestContactDevRectangle {
            flickable: gridView
        }

        function _showComicInfo(index) {
            if (infoPanelLoader.status === Loader.Null) {
                infoPanelLoader.source = Qt.resolvedUrl("../components/ComicInfoPanel.qml")
                infoPanelLoader.item.parent = comicPage
                infoPanelLoader.item.comicsModel = settingsComicsModel
                infoPanelLoader.item.homepageMenu = true
            }
            infoPanelLoader.item.index = comicsModelProxy.sourceRow(index)
            infoPanelLoader.item.showComicInfo()
        }

        function _setFavorite(index, favorite) {
            settingsComicsModel.setFavorite(comicsModelProxy.sourceRow(index), favorite)
        }

        VerticalScrollDecorator { flickable: gridView }
    }

    ComicsModel {
        id: settingsComicsModel
        Component.onCompleted: settingsComicsModel.loadAll()
    }

    ComicsModelProxy {
        id: comicsModelProxy
        comicsModel: settingsComicsModel
        sortRole: ComicsModel.SortNameRole
    }

    Loader {
        id: infoPanelLoader
    }

    SettingsInfoHint { }

    onStatusChanged: {
        if (status === PageStatus.Deactivating) {
            settingsComicsModel.saveAll()
            _settings.emitFavoritesChanged();
        }
    }

}


