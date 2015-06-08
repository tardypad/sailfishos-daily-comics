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

    SilicaListView {
        id: listView

        anchors.fill: parent
        snapMode: ListView.SnapOneItem
        orientation: ListView.HorizontalFlick

        model: comicsModelProxy

        delegate: AnimatedImage {
            width: listView.width
            height: listView.height
            opacity: Math.abs(listView.contentX - x) <= listView.width
                     ? 1.0 -  (Math.abs(listView.contentX - x) / listView.width)
                     : 0
            source: image
            fillMode: Image.PreserveAspectFit
            smooth: true
            clip: true
            asynchronous: true

            BusyIndicator {
                running: parent.status === Image.Loading
                size: BusyIndicatorSize.Large
                anchors.centerIn: parent
            }

            onStatusChanged: {
                if (status === Image.Ready && index === listView.currentIndex)
                    comicsModel.read(comicsModelProxy.sourceRow(index))
            }
        }

        onCurrentIndexChanged: {
            if (currentItem && currentItem.status === Image.Ready)
                comicsModel.read(comicsModelProxy.sourceRow(currentIndex))
        }

        onMovementEnded: currentIndex = indexAt(contentX + listView.width / 2, 100)
    }

    ComicsModelProxy {
        id: comicsModelProxy
        filterRole: ComicsModel.NewStripRole
        sortRole: ComicsModel.NameRole
    }
}
