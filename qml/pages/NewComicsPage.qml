/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "../components"

import harbour.dailycomics.Comics 1.0

Page {
    property alias comicsModel: comicsModelProxy.comicsModel

    allowedOrientations: Orientation.All

    SlideshowView {
        id: slideshowView

        model: comicsModelProxy

        delegate: SilicaFlickable {
            property alias status: comicImage.status

            width: parent.width
            height: parent.height
            contentWidth: width
            contentHeight: Math.max(comicImage.height, parent.height)

            opacity: Math.abs(x) <= slideshowView.width ? 1.0 -  (Math.abs(x) / slideshowView.width) : 0

            AnimatedImage {
                id: comicImage
                source: image
                fillMode: Image.PreserveAspectFit
                smooth: true
                clip: true
                asynchronous: true

                anchors.centerIn: parent
                width: parent.width
                height: (implicitHeight / implicitWidth ) * width

                BusyIndicator {
                    running: parent.status === Image.Loading
                    size: BusyIndicatorSize.Large
                    anchors.centerIn: parent
                }

                onStatusChanged: {
                    if (status === Image.Ready && index === slideshowView.currentIndex)
                        comicsModel.read(comicsModelProxy.sourceRow(index))
                }
            }
        }

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
        sortRole: ComicsModel.NameRole
    }

    SlideshowFlickHint { }
}
