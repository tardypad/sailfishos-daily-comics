/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "../components"
import "../delegates"

import harbour.dailycomics.Comics 1.0

Page {
    property alias comicsModel: comicsModelProxy.comicsModel

    allowedOrientations: Orientation.All

    SlideshowView {
        id: slideshowView

        model: comicsModelProxy

        delegate: NewComicsDelegate { }

        onCurrentIndexChanged: {
            if (comicsModel.newCount === 0 && !endPanel.shown)
                endPanel.showInfo()

            if (currentItem.status === Image.Ready)
                comicsModel.read(comicsModelProxy.sourceRow(currentIndex))
        }
    }

    EndPanel {
        id: endPanel
    }

    ComicsModelProxy {
        id: comicsModelProxy
        filterRole: ComicsModel.NewStripRole
        sortRole: ComicsModel.RandomRole
    }

    SlideshowFlickHint { }
}
