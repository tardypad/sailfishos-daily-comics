/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    id: bar

    property alias label: progressBar.label
    property alias minimumValue: progressBar.minimumValue
    property alias maximumValue: progressBar.maximumValue
    property alias value: progressBar.value
    property bool open: false
    property int newCount: 0
    property int errorCount: 0

    color: Theme.rgba(Theme.highlightDimmerColor, 0.9)
    width: parent.width
    height: progressBar.height + Theme.paddingSmall
    enabled: opacity != 0

    ProgressBar {
        id: progressBar
        width: parent.width - statusColumn.width - Theme.paddingSmall
        anchors {
            left: parent.left
            verticalCenter: parent.verticalCenter
        }
    }

    Column {
        id: statusColumn
        anchors {
            left: progressBar.right
            verticalCenter: parent.verticalCenter
        }
        spacing: Theme.paddingSmall
        visible: newCount > 0 || errorCount > 0
        width: visible ? Math.max(newItem.width, errorItem.width) : 0

        Behavior on width {
            NumberAnimation {}
        }

        Item {
            id: newItem
            height: newImage.height
            width: visible ? newImage.width + newLabel.width + Theme.paddingSmall : 0
            visible: newCount > 0

            Image {
                id: newImage
                source: "image://theme/icon-s-update"
                height: Theme.iconSizeSmall
                width: Theme.iconSizeSmall
                fillMode: Image.PreserveAspectFit
                smooth: true
                asynchronous: true
            }

            Label {
                id: newLabel
                anchors {
                    left: newImage.right
                    leftMargin: Theme.paddingSmall
                }
                text: qsTr("%n New", "", newCount)
                font.pixelSize: Theme.fontSizeExtraSmall
            }
        }

        Item {
            id: errorItem
            height: errorImage.height
            width: visible ? errorImage.width + errorLabel.width + Theme.paddingSmall : 0
            visible: errorCount > 0

            Image {
                id: errorImage
                source: "image://theme/icon-s-high-importance"
                height: Theme.iconSizeSmall
                width: Theme.iconSizeSmall
                fillMode: Image.PreserveAspectFit
                smooth: true
                asynchronous: true
            }

            Label {
                id: errorLabel
                anchors {
                    left: errorImage.right
                    leftMargin: Theme.paddingSmall
                }
                text: qsTr("%n Error(s)", "", errorCount)
                font.pixelSize: Theme.fontSizeExtraSmall
            }
        }
    }

    TouchBlocker {
        anchors.fill: parent
    }

    states: [
        State {
            name: "open";  when: open
            PropertyChanges { target: bar; opacity: 1.0; }
        },
        State {
            name: "closed";  when: !open
            PropertyChanges { target: bar; opacity: 0.0 }
        }
    ]

    transitions: [
        Transition {
            from: "closed"
            to: "open"
            NumberAnimation { property: "opacity" }
        },
        Transition {
            from: "open"
            to: "closed"
            SequentialAnimation {
                PropertyAnimation { duration: 2000 }
                NumberAnimation { property: "opacity" }
            }
        }
    ]
}
