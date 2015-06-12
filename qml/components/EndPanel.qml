/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

DockedPanel {
    property bool shown: false
    property bool isPortrait: (parent.isPortrait !== undefined) ? parent.isPortrait : true

    width: isPortrait ? parent.width : parent.width / 2
    height: isPortrait ? parent.height / 2 : parent.height
    contentHeight: height
    dock: isPortrait ? Dock.Bottom : Dock.Right

    MouseArea {
        anchors.fill: parent
        onClicked: hide()
    }

    Rectangle {
        anchors.fill: parent
        color: Theme.rgba(Theme.secondaryHighlightColor, 0.9)

        Column {
            anchors.centerIn: parent
            width: parent.width - 2 * Theme.paddingLarge
            spacing: 2*Theme.paddingLarge

            Label {
                text: "That's all for now!"
                width: parent.width
                horizontalAlignment: Text.AlignHCenter
                font.pixelSize: Theme.fontSizeLarge
            }

            Rectangle {
                color: Theme.secondaryHighlightColor
                width: supportLabel.width + supportImage.width + 3*Theme.paddingLarge
                height: supportLabel.height + 2*Theme.paddingLarge
                anchors.horizontalCenter: parent.horizontalCenter

                Row {
                    anchors.centerIn: parent
                    spacing: Theme.paddingLarge

                    Label {
                        id: supportLabel
                        text: "If you like the app,\nplease consider supporting\nyour favorite comic artists"
                        font.pixelSize: Theme.fontSizeSmall
                        horizontalAlignment: Text.AlignLeft
                    }

                    Image {
                        id: supportImage
                        height: Theme.iconSizeMedium
                        width: Theme.iconSizeMedium
                        anchors.verticalCenter: parent.verticalCenter
                        source: "qrc:/icon/medium/support"
                        fillMode: Image.PreserveAspectFit
                    }
                }
            }

            Button {
                anchors.horizontalCenter: parent.horizontalCenter
                text: "Return to favorites"
                onClicked: pageStack.pop()
            }
        }
    }

    function showInfo() {
        shown = true
        show()
    }
}
