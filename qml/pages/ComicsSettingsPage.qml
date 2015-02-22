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
    id: comicPage

    allowedOrientations: Orientation.All

    SilicaGridView {
        id: gridView

        property int cellSize: isPortrait ? parent.width / 3 : parent.width / 5

        anchors.fill: parent
        cellWidth: cellSize
        cellHeight: cellSize
        header: PageHeader {
            title: "Select favorites"
        }
        delegate: ComicsSettingsGridDelegate { }
        model: comicsModelProxy

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

        function _showComicInfo(index) {
            if (infoPanelLoader.status === Loader.Null) {
                infoPanelLoader.source = Qt.resolvedUrl("../components/ComicInfoPanel.qml")
                infoPanelLoader.item.parent = comicPage
                infoPanelLoader.item.comicsModel = settingsComicsModel
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
        sortRole: ComicsModel.NameRole
    }

    Loader {
        id: infoPanelLoader
    }

    onStatusChanged: {
        if (status === PageStatus.Deactivating) {
            settingsComicsModel.saveAll()
            _settings.emitFavoritesChanged();
        }
    }

}


