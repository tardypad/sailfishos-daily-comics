/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    property bool hasNew: false
    property bool hasError: false

    opacity: (hasNew || hasError) ? 1.0 : 0.0

    width: newImage.width + newLabel.width + 3*Theme.paddingSmall
    height: newImage.height + 2*Theme.paddingSmall

    Image {
        id: newImage
        anchors {
            left: parent.left
            leftMargin: Theme.paddingSmall
            bottom: parent.bottom
            bottomMargin: Theme.paddingSmall
        }
        source: hasNew ? "image://theme/icon-s-update" : "image://theme/icon-system-warning"
        height: Theme.iconSizeSmall
        width: Theme.iconSizeSmall
        fillMode: Image.PreserveAspectFit
    }

    Label {
        id: newLabel
        anchors {
            left: newImage.right
            leftMargin: Theme.paddingSmall
            bottom: parent.bottom
            bottomMargin: Theme.paddingSmall
        }
        text: hasNew ? "New" : "Error"
        font.pixelSize: Theme.fontSizeExtraSmall
    }

}
