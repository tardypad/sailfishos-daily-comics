/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "../components/"

SilicaFlickable {
    property alias status: comicImage.status

    width: parent.width
    height: parent.height
    contentWidth: width
    contentHeight: Math.max(comicImage.height, parent.height)

    opacity: Math.abs(x) <= slideshowView.width ? 1.0 -  (Math.abs(x) / slideshowView.width) : 0

    BusyIndicator {
        running: comicImage.status === Image.Loading
        size: BusyIndicatorSize.Large
        x: (slideshowView.width - width) / 2
        y: (slideshowView.height - height) / 2
    }

    ComicImage {
        id: comicImage
        animated: imageAnimated
        source: image

        anchors.centerIn: parent
        width: parent.width
        height: (implicitHeight / implicitWidth ) * width

        onStatusChanged: {
            if (status === Image.Ready && index === slideshowView.currentIndex)
                comicsModel.read(comicsModelProxy.sourceRow(index))
        }
    }
}
