/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

Loader {
    id: loader

    property string url
    property string source
    property int status

    // not the best to determine the image type based on the filename extension...
    sourceComponent: url.match(/.*\.gif$/i) != null ? animatedImage : fixedImage

    Component {
        id: animatedImage
        AnimatedImage {
            source: loader.source
            fillMode: Image.PreserveAspectFit
            smooth: true
            clip: true
            asynchronous: true

            BusyIndicator {
                running: parent.status === Image.Loading
                size: BusyIndicatorSize.Large
                anchors.centerIn: parent
            }

            Rectangle {
                anchors.fill: parent
                color: "white"
                visible: status == Image.Ready
                z: -10
            }

            onStatusChanged: loader.status = status
        }
    }

    Component {
        id: fixedImage
        Image {
            source: loader.source
            fillMode: Image.PreserveAspectFit
            smooth: true
            clip: true
            asynchronous: true

            sourceSize.width: width
            sourceSize.height: height

            BusyIndicator {
                running: parent.status === Image.Loading
                size: BusyIndicatorSize.Large
                anchors.centerIn: parent
            }

            Rectangle {
                anchors.fill: parent
                color: "white"
                visible: status == Image.Ready
                z: -10
            }

            onStatusChanged: loader.status = status
        }
    }
}
