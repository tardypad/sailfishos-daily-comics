/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

Page {

    allowedOrientations: Orientation.All

    SilicaFlickable {
        anchors.fill: parent

        contentWidth: parent.width;
        contentHeight: contentColumn.height + Theme.paddingLarge

        flickableDirection: Flickable.VerticalFlick

        Column {
            id: contentColumn

            spacing: Theme.paddingLarge
            anchors.horizontalCenter: parent.horizontalCenter
            width: parent.width

            PageHeader {
                title: "About"
            }

            Rectangle {
                color: "transparent"
                width: parent.width
                height: childrenRect.height

                Image {
                    id: coverImage
                    source: Qt.resolvedUrl("../../images/harbour-cover.jpg")
                    fillMode: Image.PreserveAspectFit
                    smooth: true
                    clip: true
                    asynchronous: true
                    width: Screen.width
                    anchors.horizontalCenter: parent.horizontalCenter
                }

                Label {
                    id: topText
                    anchors {
                        top: coverImage.bottom
                        topMargin: Theme.paddingSmall
                        horizontalCenter: parent.horizontalCenter
                    }
                    width: parent.width - 2*Theme.paddingLarge
                    text: "Your daily fix of your favorite comic strips"
                    font.pixelSize: Theme.fontSizeSmall
                    horizontalAlignment: Text.AlignHCenter
                }

                Label {
                    anchors {
                        top: topText.bottom
                        topMargin: Theme.paddingSmall
                        horizontalCenter: parent.horizontalCenter
                    }
                    width: parent.width
                    text: "version 0.1"
                    font.pixelSize: Theme.fontSizeExtraSmall
                    horizontalAlignment: Text.AlignHCenter
                }
            }

            Rectangle {
                color: Theme.rgba(Theme.highlightBackgroundColor, Theme.highlightBackgroundOpacity / 3)
                width: coverImage.width - 2*Theme.paddingLarge
                height: childrenRect.height + 2*Theme.paddingMedium
                anchors.horizontalCenter: parent.horizontalCenter

                Label {
                    id: authorLabel
                    anchors {
                        top: parent.top
                        topMargin: Theme.paddingMedium
                        horizontalCenter: parent.horizontalCenter
                    }
                    font {
                        italic: true
                        pixelSize: Theme.fontSizeExtraSmall
                    }
                    color: Theme.highlightColor
                    horizontalAlignment: Text.AlignHCenter
                    text: "by Damien Tardy-Panis"
                }

                Row {
                    id: linksRow
                    anchors {
                        top: authorLabel.bottom
                        topMargin: Theme.paddingMedium
                        horizontalCenter: parent.horizontalCenter
                    }
                    spacing: Theme.paddingLarge

                    IconButton {
                        id: twitterButton
                        height: Theme.iconSizeMedium
                        width: Theme.iconSizeMedium
                        icon {
                            source: Qt.resolvedUrl("../../images/icons/icon-m-twitter.png")
                            height: Theme.iconSizeMedium
                            fillMode: Image.PreserveAspectFit
                        }
                        onClicked: Qt.openUrlExternally("https://twitter.com/tardypad")
                    }

                    IconButton {
                        id: githubButton
                        height: Theme.iconSizeMedium
                        width: Theme.iconSizeMedium
                        icon {
                            source: Qt.resolvedUrl("../../images/icons/icon-m-github.png")
                            height: Theme.iconSizeMedium
                            fillMode: Image.PreserveAspectFit
                        }
                        onClicked: Qt.openUrlExternally("https://github.com/tardypad")
                    }

                    IconButton {
                        id: mailButton
                        height: Theme.iconSizeMedium
                        width: Theme.iconSizeMedium
                        icon {
                            source: "image://theme/icon-lock-email"
                            height: Theme.iconSizeMedium
                            fillMode: Image.PreserveAspectFit
                        }
                        onClicked: Qt.openUrlExternally("mailto:damien@tardypad.me?subject=[Daily Comics Sailfish app] ")
                    }
                }

            }

            Label {
                id: codeLabel
                width: parent.width - 2*Theme.paddingLarge
                text: "The source code is available at
                          <br/><a href='https://github.com/tardypad/daily-comics'>https://github.com/tardypad/daily-comics</a>
                          <br/>You can contact me for any remarks,
                          <br/>bugs, feature requests, ideas,... "
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                font.pixelSize: Theme.fontSizeExtraSmall
                horizontalAlignment: Text.AlignHCenter
                textFormat: Text.StyledText
                linkColor: Theme.highlightColor
                onLinkActivated: Qt.openUrlExternally(link)
            }

            Label {
                id: enjoyLabel
                width: parent.width
                text: "Enjoy!"
                font.pixelSize: Theme.fontSizeLarge
                horizontalAlignment: Text.AlignHCenter
            }
        }
    }
}
