/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "../scripts/ExternalLinks.js" as ExternalLinks

Page {

    allowedOrientations: Orientation.All

    SilicaFlickable {
        anchors.fill: parent

        contentWidth: parent.width;
        contentHeight: pageHeader.height + contentColumn.height + Theme.paddingLarge

        flickableDirection: Flickable.VerticalFlick

        PageHeader {
            id: pageHeader
            title: "About"
        }

        Column {
            id: contentColumn

            spacing: Theme.paddingLarge
            anchors {
                top: pageHeader.bottom
                horizontalCenter: parent.horizontalCenter
            }
            width: parent.width

            Rectangle {
                color: "transparent"
                width: parent.width
                height: childrenRect.height

                Image {
                    id: coverImage
                    source: Qt.resolvedUrl("../../images/harbour-cover.png")
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
                    text: "version " + Qt.application.version
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
                            source: "qrc:/icon/medium/twitter"
                            height: Theme.iconSizeMedium
                            fillMode: Image.PreserveAspectFit
                        }
                        onClicked: ExternalLinks.browse(constants.devTwitter)
                    }

                    IconButton {
                        id: githubButton
                        height: Theme.iconSizeMedium
                        width: Theme.iconSizeMedium
                        icon {
                            source: "qrc:/icon/medium/github"
                            height: Theme.iconSizeMedium
                            fillMode: Image.PreserveAspectFit
                        }
                        onClicked: ExternalLinks.browse(constants.devGithub)
                    }

                    IconButton {
                        id: mailButton
                        height: Theme.iconSizeMedium
                        width: Theme.iconSizeMedium
                        icon {
                            source: "image://theme/icon-m-mail"
                            height: Theme.iconSizeMedium
                            fillMode: Image.PreserveAspectFit
                        }
                        onClicked: ExternalLinks.mail(constants.devMail, constants.mailSubjectHeader, constants.mailBodyHeader)
                    }
                }

            }

            Label {
                id: codeLabel
                width: parent.width - 2*Theme.paddingLarge
                text: "The source code is available at
                       <br/><a href='" + constants.repoGithub + "'>" + constants.repoGithub + "</a>
                       <br/>You can contact me for any remarks,
                       <br/>bugs, feature requests, ideas,...
                       <br/>
                       <br/>Below are few resources to find new comics.
                       <br/>Let me know as well which additional comics
                       <br/>you would like to be included in the app."
                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                font.pixelSize: Theme.fontSizeExtraSmall
                horizontalAlignment: Text.AlignHCenter
                textFormat: Text.StyledText
                linkColor: Theme.highlightColor
                onLinkActivated: ExternalLinks.browse(link)
            }

            Label {
                id: resourcesLabel
                width: implicitWidth
                anchors.horizontalCenter: parent.horizontalCenter
                text: "<a href='http://gocomics.com/'>GoComics</a>
                       <br/><a href='http://tapastic.com/'>Tapastic</a>
                       <br/><a href='http://comicskingdom.com/'>Comics Kingdom</a>
                       <br/><a href='http://www.webtoons.com/'>WebToons</a>
                       <br/><a href='http://www.reddit.com/r/webcomics/'>Reddit webcomics</a>"
                font.pixelSize: Theme.fontSizeExtraSmall
                lineHeight: 1.5
                horizontalAlignment: Text.AlignLeft
                textFormat: Text.StyledText
                linkColor: Theme.highlightColor
                onLinkActivated: ExternalLinks.browse(link)
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
