/**
 * Copyright (c) 2015 Damien Tardy-Panis
 * Copyright (c) 2018 Oleg Linkin
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import harbour.dailycomics.Comics 1.0

import "../utils"
import "../components"

import "../scripts/ExternalLinks.js" as ExternalLinks

Item {
    anchors.fill: parent

    SilicaFlickable {
        id: flickable

        anchors.fill: parent
        //
        property bool scaled: false

        readonly property bool enableZoom: true
        property bool active: true
        readonly property bool error: comicImage.status == Image.Error

        property real _fittedScale: Math.min(maximumZoom, Math.min(width / implicitWidth,
                                                                   height / implicitHeight))
        property real _scale
        // Calculate a default value which produces approximately same level of zoom
        // on devices with different screen resolutions.
        property real maximumZoom: Math.max(Screen.width, Screen.height) / 200
        property int _maximumZoomedWidth: _fullWidth * maximumZoom
        property int _maximumZoomedHeight: _fullHeight * maximumZoom
        property int _minimumZoomedWidth: implicitWidth * _fittedScale
        property int _minimumZoomedHeight: implicitHeight * _fittedScale
        property bool _zoomAllowed: enableZoom && _fittedScale !== maximumZoom
        property int _fullWidth: Math.max(comicImage.implicitWidth, largeComicImage.implicitWidth)
        property int _fullHeight: Math.max(comicImage.implicitHeight, largeComicImage.implicitHeight)

        signal clicked

        pressDelay: 0

        enabled: !zoomOutAnimation.running
        flickableDirection: Flickable.HorizontalAndVerticalFlick

        implicitWidth: comicImage.implicitWidth
        implicitHeight: comicImage.implicitHeight

        contentWidth: container.width
        contentHeight: container.height

        readonly property bool _active: active
        on_ActiveChanged: {
            if (!_active) {
                _resetScale()
                largeComicImage.source = ""
            }
        }
        interactive: scaled && !mouseArea.horizontalDragUnused

        function _resetScale() {
            if (scaled) {
                _scale = _fittedScale
                scaled = false
            }
        }

        function _scaleImage(scale, center, prevCenter) {
            if (largeComicImage.source != comicImage.source) {
                largeComicImage.source = comicImage.source
            }

            var newWidth
            var newHeight
            var oldWidth = contentWidth
            var oldHeight = contentHeight

            newWidth = (comicImage.width) * scale
            if (newWidth <= flickable._minimumZoomedWidth) {
                _resetScale()
                return
            } else {
                newWidth = Math.min(newWidth, flickable._maximumZoomedWidth)
                _scale = newWidth / implicitWidth
                newHeight = comicImage.height
            }
            // move center
            contentX += prevCenter.x - center.x
            contentY += prevCenter.y - center.y

            // scale about center
            if (newWidth > flickable.width)
                contentX -= (oldWidth - newWidth)/(oldWidth/prevCenter.x)
            if (newHeight > flickable.height)
                contentY -= (oldHeight - newHeight)/(oldHeight/prevCenter.y)

            scaled = true
        }

        Binding { // Update scale on orientation changes
            target: flickable
            when: !flickable.scaled
            property: "_scale"
            value: flickable._fittedScale
        }

        Connections {
            target: pageStack
            onDragInProgressChanged: {
                if (pageStack.dragInProgress && pageStack._noGrabbing) {
                    pageStack._grabMouse()
                }
            }
        }

        children: ScrollDecorator {}

        PinchArea {
            id: container
            enabled: comicImage.status == Image.Ready
            onPinchUpdated: {
                if (flickable._zoomAllowed)
                    flickable._scaleImage(1.0 + pinch.scale - pinch.previousScale,
                            pinch.center, pinch.previousCenter)
            }
            onPinchFinished: flickable.returnToBounds()
            width: Math.max(flickable.width, comicImage.width)
            height: Math.max(flickable.height, comicImage.height)

            AnimatedImage {
                id: comicImage
                property var errorLabel
                objectName: "zoomableImage"

                smooth: !(flickable.movingVertically || flickable.movingHorizontally)
                width: Math.ceil(implicitWidth * flickable._scale)
                height: Math.ceil(implicitHeight * flickable._scale)
                fillMode:  Image.PreserveAspectFit
                asynchronous: true
                anchors.centerIn: parent
                cache: false
                source: !comic.error && !indicator.busy ? comic.stripImagePath : ''

                onSourceChanged: {
                    flickable.scaled = false
                }

                onStatusChanged: {
                    if (status === Image.Ready)
                        comic.read()
                    else if (status === Image.Error) {
                        indicator.displayError(qsTr("Image error"), qsTr("Can't display strip"))
                        comic.setError()
                    }
                }

                opacity: status == Image.Ready ? 1 : 0
                Behavior on opacity { FadeAnimation{} }
            }
            AnimatedImage {
                id: largeComicImage
                    width: 3264
                    height: 3264
                cache: false
                asynchronous: true
                anchors.fill: comicImage
            }

            BusyIndicator {
                running: comicImage.status === Image.Loading &&
                        !delayBusyIndicator.running
                size: BusyIndicatorSize.Large
                anchors.centerIn: parent
                Timer {
                    id: delayBusyIndicator
                    running: comicImage.status === Image.Loading
                    interval: 1000
                }
            }

            MouseArea {
                id: mouseArea

                property int startX
                property int startY
                property bool horizontalDragUnused
                property bool verticalDragUnused

                function reset() {
                    verticalDragUnused = false
                    horizontalDragUnused = false
                }
                onPressed: {
                    reset()
                    startX = mouseX
                    startY = mouseY
                }
                onPositionChanged: {
                    if (container.pinch.active) return
                    if (mouseX - startX > Theme.startDragDistance && flickable.atXBeginning
                            || mouseX - startX < -Theme.startDragDistance && flickable.atXEnd) {
                        horizontalDragUnused = true
                    } else if (mouseY - startY > Theme.startDragDistance && flickable.atYBeginning
                               || mouseY - startY < -Theme.startDragDistance && flickable.atYEnd) {

                        verticalDragUnused = true
                    }
                }
                onClicked: overlay.active = !overlay.active
                onDoubleClicked: {
                    if (flickable._scale !== flickable._fittedScale) {
                        zoomOutAnimation.start()
                    }
                }

                anchors.fill: parent

                ParallelAnimation {
                    id: zoomOutAnimation
                    SequentialAnimation {
                        NumberAnimation {
                            target: flickable
                            property: "_scale"
                            to: flickable._fittedScale
                            easing.type: Easing.InOutQuad
                            duration: 200
                        }
                        ScriptAction {
                            script: flickable.scaled = false
                        }
                    }
                    NumberAnimation {
                        target: flickable
                        properties: "contentX, contentY"
                        to: 0
                        easing.type: Easing.InOutQuad
                        duration: 200
                    }
                }
            }
        }

        LoadingIndicator {
            id: indicator
            model: comic
            flickable: flickable
            loadingText: qsTr("Loading comic")
            defaultErrorText: qsTr("Can't display comic")
            networkErrorText: qsTr("Can't download comic")
            parsingErrorText: qsTr("Can't extract comic")
            savingErrorText: qsTr("Can't save comic")
        }

        ErrorContactDevRectangle {
            comicName: comic.name
            flickable: flickable
            active: indicator.error
            z: 10
        }

        BusyIndicator {
            anchors.centerIn: parent
            running: comicImage.status === Image.Loading
            size: BusyIndicatorSize.Large
        }
    }

    ImageOverlay {
        id: overlay

        visible: comicImage.source !== "" && !comic.error && !indicator.busy

        comicProxy: comic
        comicIndex: index
        comicsModel: model

        anchors.fill: parent
        z: 2
    }
}
