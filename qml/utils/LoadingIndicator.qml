/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

Item {
    id: loadingIndicator

    property Item flickable
    property alias model: connections.target
    property alias loadingText: progressIndicator.label
    property string defaultErrorText
    property string networkErrorText
    property string parsingErrorText
    property string savingErrorText

    property bool busy: false
    property bool error: false

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

    Component {
        id: errorComponent
        ViewPlaceholder {
            text: qsTr("An error occured")
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

    Connections {
        id: connections
        onFetchSucceeded: state = "complete"
        onFetchStarted: state = "fetching"
        onNetworkError: displayError(qsTr("Network error"), networkErrorText)
        onParsingError: displayError(qsTr("Parsing error"), parsingErrorText)
        onSavingError: displayError(qsTr("Saving error"), savingErrorText)
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

    function displayError(text, hintText) {
        state = "error"
        placeholderLoader.item.text = text
        placeholderLoader.item.hintText = hintText
    }

    function removePlaceholder() {
        if (placeholderLoader.status === Loader.Ready) {
            placeholderLoader.item.enabled = false
        }
    }

    states: [
        State {
            name: "init"
            PropertyChanges { target: loadingIndicator; visible: false; busy: false; error: false }
        },
        State {
            name: "fetching"
            PropertyChanges { target: loadingIndicator; visible: true; busy: true; error: false }
            StateChangeScript { script: removePlaceholder() }
        },
        State {
            name: "error"
            PropertyChanges { target: loadingIndicator; visible: false; busy: true; error: true }
            StateChangeScript {
                script: {
                    placeholderLoader.sourceComponent = errorComponent
                    placeholderLoader.item.enabled = true
                }
            }
        },
        State {
            name: "complete"
            PropertyChanges { target: loadingIndicator; visible: false; busy: false; error: false }
            StateChangeScript { script: removePlaceholder() }
        }]
}
