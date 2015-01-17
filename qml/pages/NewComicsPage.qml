/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import harbour.dailycomics.Comics 1.0

Page {
    property alias comicsModel: comicsModelProxy.comicsModel

    allowedOrientations: Orientation.All

    SlideshowView {
        id: slideshowView

        model: comicsModelProxy

        delegate: Image {
            width: parent.width
            height: parent.height
            source: image
            fillMode: Image.PreserveAspectFit
            smooth: true
            clip: true
            asynchronous: true
            opacity: Math.abs(x) <= slideshowView.width ? 1.0 -  (Math.abs(x) / slideshowView.width) : 0

            BusyIndicator {
                running: parent.status === Image.Loading
                size: BusyIndicatorSize.Large
                anchors.centerIn: parent
            }
        }
    }

    ComicsModelProxy {
        id: comicsModelProxy
    }
}
