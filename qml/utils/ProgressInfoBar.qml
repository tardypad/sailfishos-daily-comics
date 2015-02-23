/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

Rectangle {
    property alias label: progressBar.label
    property alias minimumValue: progressBar.minimumValue
    property alias maximumValue: progressBar.maximumValue
    property alias value: progressBar.value
    property bool open: false

    color: Theme.rgba(Theme.secondaryHighlightColor, 0.9)
    width: parent.width
    height: 100
    opacity: open ? 1.0 : 0.0
    enabled: open

    ProgressBar {
        id: progressBar
        width: parent.width
        anchors.centerIn: parent
    }

    Behavior on opacity {
        NumberAnimation { }
    }
}
