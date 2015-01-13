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

        property int cellSize: window.portrait ? parent.width / 3 : parent.width / 5

        anchors.fill: parent
        cellWidth: cellSize
        cellHeight: cellSize
        header: PageHeader {
            title: "Select favorites"
        }
        delegate: ComicsSettingsGridDelegate { }
        model: comicsModel

        PullDownMenu {
            MenuItem {
                text: "Clear all"
                onClicked: comicsModel.unfavoriteAll()
                visible: comicsModel.favoritesCount > 0

            }
            MenuItem {
                text: "Select all"
                onClicked: comicsModel.favoriteAll()
                visible: comicsModel.favoritesCount !== comicsModel.count
            }
        }

        function _showComicInfo(id) {
            if (infoPanelLoader.status === Loader.Null) {
                infoPanelLoader.source = Qt.resolvedUrl("../components/ComicInfoPanel.qml")
                infoPanelLoader.item.parent = comicPage
            }
            infoPanelLoader.item.showComic(id)
        }

        VerticalScrollDecorator { flickable: gridView }
    }

    ComicsModel {
        id: comicsModel
        Component.onCompleted: comicsModel.loadAll()
    }

    Loader {
        id: infoPanelLoader
    }

    onStatusChanged: {
        if (status === PageStatus.Deactivating) {
            _settings.saveFavoriteIds(comicsModel.favoriteIds());
        }
    }

}


