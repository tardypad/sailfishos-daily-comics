/**
 * Copyright (c) 2015 Damien Tardy-Panis
 * Copyright (c) 2018-2019 Oleg Linkin <maledictusdemagog@gmail.com>
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.dailycomics.Comics 1.0

import "../components"
import "../delegates"
import "../utils"

Page {
    id: page
    property alias comicsModel: comicsModelProxy.comicsModel

    allowedOrientations: Orientation.All

    SlideshowView {
        id: slideshowView

        anchors.fill: parent
        clip: true

        model: comicsModelProxy

        delegate: ComicItem {
            id: zoomableImage
            property bool markRead: false
            comicProxy: ComicProxy { }

            width: slideshowView.width
            height: slideshowView.height

            name: name
            homepage: comicProxy.homepage
            imagePath: !comicProxy.error && !indicator.busy ? image : ""
            indicator.error: comicProxy.error

            onRead: markRead = true
            onSetError: {
                indicator.displayError(errorText, hintText)
                comicProxy.setError()
            }
            onClicked: overlay.active = !overlay.active
        }

        function changeCurrentIndex(index) {
            if (comicsModel.newCount === 0 && !endPanel.shown) {
                endPanel.showInfo()
            }

            currentItem.comicProxy.comic = comicsModel.comicAt(comicsModelProxy.sourceRow(index))
            overlay.comicProxy = currentItem.comicProxy
            if (currentItem.markRead) {
                comicsModel.read(comicsModelProxy.sourceRow(index))
            }
        }

        Component.onCompleted: {
            changeCurrentIndex(0)
        }

        onCurrentIndexChanged: {
            if (currentIndex < 0) {
                return
            }
            changeCurrentIndex(currentIndex)
        }
    }

    ImageOverlay {
        id: overlay
        anchors.fill: parent

        visible: !endPanel.open && !slideshowView.currentItem.comicProxy.error &&
                slideshowView.currentItem.ready
        comicIndex: comicsModelProxy.sourceRow(slideshowView.currentIndex)
        comicsModel: page.comicsModel
        z: slideshowView.z + 1
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
