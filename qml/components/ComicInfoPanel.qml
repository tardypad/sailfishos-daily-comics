/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import Comics 1.0

DockedPanel {
    id: comicInfoPanel

    width: window.portrait ? parent.width : parent.height
    height: window.portrait
            ? infoColumn.height + 2*Theme.paddingMedium
            : parent.height
    dock: window.portrait ? Dock.Bottom : Dock.Right

    function showComic(comicId) {
        comic.comicId = comicId
        show()
    }

    Comic {
        id: comic
    }

    MouseArea {
        anchors.fill: parent
        onClicked: hide()
    }

    property int _headerWidth: 125
    property int _textWidth: width - _headerWidth - Theme.paddingLarge

    Rectangle {
        anchors.fill: parent
        color: Theme.rgba(Theme.secondaryHighlightColor, 0.9)

        Column {
            id: infoColumn
            spacing: Theme.paddingMedium
            anchors.centerIn: parent

            Label {
                id: nameLabel
                text: comic.name
                width: parent.width - 2 * Theme.paddingMedium
                font.pixelSize: Theme.fontSizeMedium
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Row {
                spacing: Theme.paddingLarge
                Label {
                    id: authorHeaderLabel
                    text: "Author"
                    width: _headerWidth
                    font {
                        italic: true
                        pixelSize: Theme.fontSizeExtraSmall
                    }
                    color: Theme.secondaryColor
                    horizontalAlignment: Text.AlignRight
                }
                Label {
                    id: authorLabel
                    text: comic.author
                    width: _textWidth
                    font.pixelSize: Theme.fontSizeSmall
                    anchors.baseline: authorHeaderLabel.baseline
                    truncationMode: TruncationMode.Fade
                }
            }
            Row {
                spacing: Theme.paddingLarge
                Label {
                    id: countryHeaderLabel
                    text: "Country"
                    width: _headerWidth
                    font {
                        italic: true
                        pixelSize: Theme.fontSizeExtraSmall
                    }
                    color: Theme.secondaryColor
                    horizontalAlignment: Text.AlignRight
                }
                Label {
                    id: countryLabel
                    text: comic.country
                    width: _textWidth
                    font.pixelSize: Theme.fontSizeSmall
                    anchors.baseline: countryHeaderLabel.baseline
                    truncationMode: TruncationMode.Fade
                }
            }
            Row {
                spacing: Theme.paddingLarge
                Label {
                    id: languageHeaderLabel
                    text: "Language"
                    width: _headerWidth
                    font {
                        italic: true
                        pixelSize: Theme.fontSizeExtraSmall
                    }
                    color: Theme.secondaryColor
                    horizontalAlignment: Text.AlignRight
                }
                Label {
                    id: languageLabel
                    text: comic.language
                    width: _textWidth
                    font.pixelSize: Theme.fontSizeSmall
                    anchors.baseline: languageHeaderLabel.baseline
                    truncationMode: TruncationMode.Fade
                }
            }
            Row {
                spacing: Theme.paddingLarge
                Label {
                    id: publicationHeaderLabel
                    text: "Publication"
                    width: _headerWidth
                    font {
                        italic: true
                        pixelSize: Theme.fontSizeExtraSmall
                    }
                    color: Theme.secondaryColor
                    horizontalAlignment: Text.AlignRight
                }
                Label {
                    property string _startYear: Qt.formatDate(comic.startDate, "yyyy")
                    property string _endYear: Qt.formatDate(comic.endDate, "yyyy") != Qt.formatDateTime(new Date(), "yyyy")
                                              ? Qt.formatDate(comic.endDate, "yyyy")
                                              : "present"

                    id: publicationLabel
                    text: _startYear + " - " + _endYear
                    width: _textWidth
                    font.pixelSize: Theme.fontSizeSmall
                    anchors.baseline: publicationHeaderLabel.baseline
                    truncationMode: TruncationMode.Fade
                }
            }

            Image {
                id: exampleImage
                source: comic.comicId ? Qt.resolvedUrl("../../images/comics/examples/"+comic.comicId+".jpg") : ''
                fillMode: Image.PreserveAspectFit
                smooth: true
                asynchronous: true

                width: parent.width - 2 * Theme.paddingMedium
                height: window.portrait
                        ? Math.min(window.height / 4, implicitHeight)
                        : comicInfoPanel.height - (nameLabel.height + 7 * Theme.paddingMedium
                          + authorLabel.height + countryLabel.height + languageLabel.height + publicationLabel.height)

                anchors.horizontalCenter: parent.horizontalCenter
            }
        }

    }

    PushUpMenu {
        MenuItem {
            text: "Go to homepage"
            onClicked: Qt.openUrlExternally(comic.homepage)
        }
    }
}
