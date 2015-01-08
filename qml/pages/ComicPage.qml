/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import Comics 1.0

Page {

    allowedOrientations: Orientation.All

    property alias comicId: comic.comicId

    Comic {
        id: comic
    }

    Image {
        source: comic.currentStripUrl
        fillMode: Image.PreserveAspectFit
        smooth: true
        clip: true
        asynchronous: true
        anchors.fill: parent
    }

}
