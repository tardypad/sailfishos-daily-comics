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

    property color mainColor
    property alias fetchingProgressValue: progressCircle.value
    property bool hasNew: false
    property bool hasError: false
    property bool isFetching: false

    property color secondaryColor: Qt.darker(mainColor, 1.1)

    width: image.width + label.width
           + (label.visible ? 3 : 2) * Theme.paddingSmall
    height: image.height + 2*Theme.paddingSmall

    color: secondaryColor

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
    }

    ProgressCircle {
        id: progressCircle
        anchors {
            left: parent.left
            leftMargin: Theme.paddingSmall
            bottom: parent.bottom
            bottomMargin: Theme.paddingSmall
        }

        height: Theme.iconSizeSmall
        width: Theme.iconSizeSmall

        progressColor: secondaryColor
        backgroundColor: mainColor

        SequentialAnimation on backgroundColor {
            id: blinkingAnimation
            running: true
            loops: Animation.Infinite
            ColorAnimation { from: mainColor; to: secondaryColor; duration: 500 }
            ColorAnimation { from: secondaryColor; to: mainColor;  duration: 500 }
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
          PropertyChanges { target: statusRectangle;   opacity: 0.0 }
          PropertyChanges { target: blinkingAnimation; running: false }
        },
        State {
            name: "new"
            when: !isFetching && hasNew && !hasError
            PropertyChanges { target: statusRectangle;   opacity: 1.0 }
            PropertyChanges { target: image;             source: "image://theme/icon-s-update" }
            PropertyChanges { target: progressCircle;    opacity: 0.0 }
            PropertyChanges { target: blinkingAnimation; running: false }
            PropertyChanges { target: label;             text: "New"; visible: true; }
        },
        State {
            name: "error"
            when: !isFetching && hasError
            PropertyChanges { target: statusRectangle;   opacity: 1.0 }
            PropertyChanges { target: image;             source: "image://theme/icon-system-warning" }
            PropertyChanges { target: progressCircle;    opacity: 0.0 }
            PropertyChanges { target: blinkingAnimation; running: false }
            PropertyChanges { target: label;             text: "Error"; visible: true; }
        },
        State {
            name: "fetching"
            when: isFetching
            PropertyChanges { target: statusRectangle;   opacity: 1.0 }
            PropertyChanges { target: image;             opacity: 0.0 }
            PropertyChanges { target: progressCircle;    opacity: 1.0 }
            PropertyChanges { target: blinkingAnimation; running: true }
            PropertyChanges { target: label;             visible: false }
        }]
}
