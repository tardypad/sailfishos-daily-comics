/**
 * Copyright (c) 2015 Damien Tardy-Panis
 * Copyright (c) 2020 Mirian Margiani
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "../scripts/ExternalLinks.js" as ExternalLinks

Item {
    id: loadingIndicator
    anchors.fill: parent

    property string comicName: ""
    property alias model: connections.target
    property alias loadingText: progressIndicator.label
    property string defaultErrorText
    property string networkErrorText
    property string parsingErrorText
    property string savingErrorText
    property string _currentErrorTitle: qsTr("An error occured")
    property string _currentErrorDescription: defaultErrorText

    visible: false
    property bool busy: false
    property bool error: false
    property bool overlayVisible: (busy || error)

    PinchArea {
        anchors.fill: parent
        enabled: overlayVisible // disables all PinchAreas below the overlay
    }

    Rectangle {
        anchors.fill: parent
        color: Theme.highlightDimmerColor
        opacity: Theme.opacityOverlay
        visible: overlayVisible
    }

    Loader {
        id: placeholderLoader
        width: parent.width - 2*Theme.paddingLarge
        anchors.centerIn: parent
    }

    ProgressBar {
        id: progressIndicator
        anchors.centerIn: parent
        width: parent.width - 2*Theme.paddingLarge
        maximumValue: -1; minimumValue: maximumValue > 0 ? 0 : -1
        indeterminate: maximumValue < 0
        visible: busy && parent.state !== "error"
    }

    Component {
        id: errorComponent
        ViewPlaceholder {
            text: _currentErrorTitle
            hintText: _currentErrorDescription
            _mainLabel.color: Theme.primaryColor
            _hintLabel.color: Theme.primaryColor

            Row {
                spacing: 3*Theme.paddingLarge
                anchors {
                    horizontalCenter: parent.horizontalCenter
                    top: parent.bottom; topMargin: 2*Theme.paddingLarge
                }
                IconButton {
                    icon.width: Theme.iconSizeLarge; icon.height: icon.width
                    icon.source: "image://theme/icon-m-region"
                    onClicked: ExternalLinks.browse(model.homepage)
                }
                IconButton {
                    icon.width: Theme.iconSizeLarge; icon.height: icon.width
                    icon.source: "image://theme/icon-m-refresh"
                    onClicked: _fetch()
                }
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
        onDownloadProgress: {
            progressIndicator.maximumValue = bytesTotal
            progressIndicator.value = bytesReceived
        }
    }

    onVisibleChanged: {
        if (state !== "error") return
        if (visible) showPlaceholder()
        else removePlaceholder()
    }

    function _fetch() {
        progressIndicator.maximumValue = -1
        model.fetch()
    }

    function displayError(text, hintText) {
        state = "error"
        _currentErrorTitle = text
        _currentErrorDescription = hintText
    }

    function removePlaceholder() {
        if (placeholderLoader.status === Loader.Ready && placeholderLoader.item) {
            placeholderLoader.item.enabled = false
        }
    }

    function showPlaceholder() {
        placeholderLoader.sourceComponent = errorComponent
        if (placeholderLoader.item) placeholderLoader.item.enabled = true
    }

    states: [
        State {
            name: "fetching"
            PropertyChanges { target: loadingIndicator; busy: true; error: false; visible: true }
            StateChangeScript { script: removePlaceholder() }
        },
        State {
            name: "error"
            PropertyChanges { target: loadingIndicator; busy: true; error: true; visible: true }
            StateChangeScript { script: showPlaceholder() }
        },
        State {
            name: "complete"
            PropertyChanges { target: loadingIndicator; busy: false; error: false; visible: false }
        }
    ]
}
