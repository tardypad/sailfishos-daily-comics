/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: statusRectangle

    property bool hasNew: false
    property bool hasError: false
    property bool isFetching: false

    width: image.width + label.width
           + (label.visible ? 3 : 2) * Theme.paddingSmall
    height: image.height + 2*Theme.paddingSmall

    state: "invisible"

    Image {
        id: image
        anchors {
            left: parent.left
            leftMargin: Theme.paddingSmall
            bottom: parent.bottom
            bottomMargin: Theme.paddingSmall
        }
        height: Theme.iconSizeSmall
        width: Theme.iconSizeSmall
        fillMode: Image.PreserveAspectFit
        smooth: true
        asynchronous: true

        RotationAnimation on rotation {
            id: imageRotation
            loops: Animation.Infinite
            from: 0
            to: 360
            duration: 1000
        }
    }

    Label {
        id: label
        anchors {
            left: image.right
            leftMargin: Theme.paddingSmall
            bottom: parent.bottom
            bottomMargin: Theme.paddingSmall
        }
        font.pixelSize: Theme.fontSizeExtraSmall
    }


    states: [
        State {
          name: "invisible"
          when: !isFetching && !hasNew && !hasError
          PropertyChanges { target: statusRectangle; opacity: 0.0 }
          PropertyChanges { target: imageRotation;   running: false }
        },
        State {
            name: "new"
            when: !isFetching && hasNew && !hasError
            PropertyChanges { target: statusRectangle; opacity: 1.0 }
            PropertyChanges { target: image;           source: "image://theme/icon-s-update"; rotation: 0 }
            PropertyChanges { target: label;           text: "New"; visible: true; }
            PropertyChanges { target: imageRotation;   running: false }
        },
        State {
            name: "error"
            when: !isFetching && hasError
            PropertyChanges { target: statusRectangle; opacity: 1.0 }
            PropertyChanges { target: image;           source: "image://theme/icon-system-warning"; rotation: 0 }
            PropertyChanges { target: label;           text: "Error"; visible: true; }
            PropertyChanges { target: imageRotation;   running: false }
        },
        State {
            name: "fetching"
            when: isFetching
            PropertyChanges { target: statusRectangle; opacity: 1.0 }
            PropertyChanges { target: image;           source: "image://theme/icon-s-sync" }
            PropertyChanges { target: label;           visible: false }
            PropertyChanges { target: imageRotation;   running: true }
        }]
}
