/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "../scripts/ExternalLinks.js" as ExternalLinks

Item {
    id: loadingIndicator

    property Item flickable
    property alias model: connections.target
    property alias loadingText: progressIndicator.label
    property string defaultErrorText
    property string networkErrorText
    property string parsingErrorText

    parent: flickable.contentItem

    y: flickable.originY + (flickable.height - height) / 2
    width: parent.width - 2*Theme.paddingLarge
    height: progressIndicator.height
    anchors.horizontalCenter: parent.horizontalCenter

    state: "init"

    ProgressBar {
        id: progressIndicator
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width
        indeterminate: true
    }

    Loader {
        id: placeholderLoader
        parent: flickable
    }

    Loader {
        id: devContactLoader
        parent: flickable
    }

    Component {
        id: errorComponent
        ViewPlaceholder {
            text: "An error occured"
            hintText: defaultErrorText

            IconButton {
                anchors.horizontalCenter: parent.horizontalCenter
                y: parent.height + Theme.paddingLarge
                icon.width: Theme.iconSizeLarge
                icon.height: Theme.iconSizeLarge
                icon.asynchronous: true
                icon.source: "image://theme/icon-m-refresh"
                onClicked: _fetch()
                z: 10
            }
        }
    }

    Component {
        id: devContactComponent
        Rectangle {
            color: Theme.rgba(Theme.highlightBackgroundColor, Theme.highlightBackgroundOpacity / 3)
            x: flickable.originX + flickable.width - (width + Theme.paddingLarge)
            y: flickable.originY + flickable.height - (height + Theme.paddingLarge)
            width: devLabel.width + mailButton.width + 3*Theme.paddingSmall
            height: devLabel.height + 2*Theme.paddingSmall

            Label {
                id: devLabel
                anchors {
                    top: parent.top
                    topMargin: Theme.paddingSmall
                    left: parent.left
                    leftMargin: Theme.paddingSmall
                }
                text: "Please contact me\nif the problem persists"
                font.pixelSize: Theme.fontSizeExtraSmall
            }

            IconButton {
                id: mailButton
                height: Theme.iconSizeMedium
                width: Theme.iconSizeMedium
                anchors {
                    left: devLabel.right
                    leftMargin: Theme.paddingSmall
                    verticalCenter: parent.verticalCenter
                }
                icon {
                    source: "image://theme/icon-lock-email"
                    height: Theme.iconSizeMedium
                    fillMode: Image.PreserveAspectFit
                }
            }

            MouseArea {
                anchors.fill: parent
                onClicked: ExternalLinks.mail("damien@tardypad.me", "[Daily Comics Sailfish app error] ")
            }
        }
    }

    Connections {
        id: connections
        onDataParsed: state = "complete"
        onFetchStarted: state = "fetching"
        onNetworkError: _displayError("Network error", networkErrorText)
        onParsingError: _displayError("Parsing error", parsingErrorText)
        onDownloadProgress: _updateProgress(bytesReceived, bytesTotal)
    }

    function _fetch() {
        progressIndicator.indeterminate = true
        model.fetch()
    }

    function _updateProgress(bytesReceived, bytesTotal) {
        if (bytesTotal === -1) {
            progressIndicator.indeterminate = true
        } else {
            progressIndicator.indeterminate = false
            progressIndicator.value = bytesReceived / bytesTotal
        }
    }

    function _displayError(text, hintText) {
        state = "error"
        placeholderLoader.item.text = text
        placeholderLoader.item.hintText = hintText
    }

    function removePlaceholder() {
        if (placeholderLoader.status === Loader.Ready) {
            placeholderLoader.item.enabled = false
        }
    }

    function removeDevContact() {
        if (devContactLoader.status === Loader.Ready) {
            devContactLoader.item.visible = false
        }
    }

    states: [
        State {
            name: "init"
            PropertyChanges { target: loadingIndicator; visible: false }
        },
        State {
            name: "fetching"
            PropertyChanges { target: loadingIndicator; visible: true }
            StateChangeScript {
                script: {
                    removePlaceholder()
                    removeDevContact()
                }
            }
        },
        State {
            name: "error"
            PropertyChanges { target: loadingIndicator; visible: false }
            StateChangeScript {
                script: {
                    placeholderLoader.sourceComponent = errorComponent
                    placeholderLoader.item.enabled = true
                    devContactLoader.sourceComponent = devContactComponent
                    devContactLoader.item.visible = true
                }
            }
        },
        State {
            name: "complete"
            PropertyChanges { target: loadingIndicator; visible: false }
            StateChangeScript {
                script: {
                    removePlaceholder()
                    removeDevContact()
                }
            }
        }]
}
