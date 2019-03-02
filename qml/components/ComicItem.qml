/**
 * Copyright (c) 2018-2019 Oleg Linkin <maledictusdemagog@gmail.com>
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

ZoomableImage {
    id: zoomableImage

    property alias comicProxy: indicator.model
    property alias indicator: indicator

    ready: imagePath !== "" && !indicator.busy

    LoadingIndicator {
        id: indicator
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
