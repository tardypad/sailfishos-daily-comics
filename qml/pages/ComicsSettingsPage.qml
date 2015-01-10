/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import Comics 1.0

import "../delegates"

Page {

    allowedOrientations: Orientation.All

    SilicaGridView {
        id: gridView

        property int cellSize: (orientation === Orientation.Portrait || orientation === Orientation.PortraitInverted)
                               ? parent.width / 3
                               : parent.width / 5

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

        VerticalScrollDecorator { flickable: gridView }
    }

    ComicsModel {
        id: comicsModel
        Component.onCompleted: comicsModel.loadAll()
    }

    onStatusChanged: {
        if (status === PageStatus.Deactivating) {
            _settings.saveFavoriteIds(comicsModel.favoriteIds());
        }
    }

}


