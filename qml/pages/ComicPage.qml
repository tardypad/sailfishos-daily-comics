/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import harbour.dailycomics.Comics 1.0

import "../utils"
import "../components"

import "../scripts/ExternalLinks.js" as ExternalLinks

Page {
    id: comicPage

    allowedOrientations: Orientation.All

    property int index
    property ComicsModel comicsModel

    ComicProxy {
        id: comicProxy
    }

    ZoomableImage {
        id: zoomableImage
        anchors.fill: parent
        name: comicProxy.name
        imagePath: !comicProxy.error && !indicator.busy ? comicProxy.stripImagePath : ""
        error: comicProxy.error
        ready: imagePath !== "" && !indicator.busy

        onRead: comicProxy.read()
        onSetError: {
            indicator.displayError(errorText, hintText)
            comicProxy.setError()
        }
        onClicked: overlay.active = !overlay.active

        LoadingIndicator {
            id: indicator
            model: comicProxy
            flickable: zoomableImage
            loadingText: qsTr("Loading comic")
            defaultErrorText: qsTr("Can't display comic")
            networkErrorText: qsTr("Can't download comic")
            parsingErrorText: qsTr("Can't extract comic")
            savingErrorText: qsTr("Can't save comic")
        }

        ErrorContactDevRectangle {
            comicName: zoomableImage.name
            flickable: zoomableImage
            active: indicator.error
            z: 10
        }
    }

    ImageOverlay {
        id: overlay
        anchors.fill: parent

        visible: zoomableImage.ready && !comicProxy.error
        comicProxy: comicProxy
        comicIndex: comicPage.index
        comicsModel: comicPage.comicsModel
        z: 2
    }

    Component.onCompleted: {
        comicProxy.setComic(comicsModel.comicAt(index))
        comicProxy.fetch()
    }
}
