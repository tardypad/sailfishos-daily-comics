/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import Comics 1.0
import Settings 1.0

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
    }

    ComicsModel {
        id: comicsModel
    }

    Settings {
        id: settings
    }

    Component.onCompleted: {
        comicsModel.loadAll(settings.favoriteIds())
    }

    onStatusChanged: {
        if (status === PageStatus.Deactivating) {
            settings.saveFavoriteIds(comicsModel.selected());
        }
    }

}


