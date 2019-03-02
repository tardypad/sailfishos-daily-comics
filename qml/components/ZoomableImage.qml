/**
 * Copyright (c) 2015 Damien Tardy-Panis
 * Copyright (c) 2018-2019 Oleg Linkin <maledictusdemagog@gmail.com>
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

SilicaFlickable {
    id: zoomableImage

    property string name
    property string imagePath
    property bool error: false
    property bool ready: false
    signal read()
    signal setError(var errorText, var hintText)

    signal clicked()

    property bool scaled: false
    readonly property bool enableZoom: true
    property bool active: true
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
        if (newWidth <= zoomableImage._minimumZoomedWidth) {
            _resetScale()
            return
        } else {
            newWidth = Math.min(newWidth, zoomableImage._maximumZoomedWidth)
            _scale = newWidth / implicitWidth
            newHeight = comicImage.height
        }
        // move center
        contentX += prevCenter.x - center.x
        contentY += prevCenter.y - center.y

        // scale about center
        if (newWidth > zoomableImage.width)
            contentX -= (oldWidth - newWidth)/(oldWidth/prevCenter.x)
        if (newHeight > zoomableImage.height)
            contentY -= (oldHeight - newHeight)/(oldHeight/prevCenter.y)

        scaled = true
    }

    Binding { // Update scale on orientation changes
        target: zoomableImage
        when: !zoomableImage.scaled
        property: "_scale"
        value: zoomableImage._fittedScale
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
            if (zoomableImage._zoomAllowed)
                zoomableImage._scaleImage(1.0 + pinch.scale - pinch.previousScale,
                        pinch.center, pinch.previousCenter)
        }
        onPinchFinished: zoomableImage.returnToBounds()
        width: Math.max(zoomableImage.width, comicImage.width)
        height: Math.max(zoomableImage.height, comicImage.height)

        AnimatedImage {
            id: comicImage
            property var errorLabel
            objectName: "zoomableImage"

            smooth: !(zoomableImage.movingVertically || zoomableImage.movingHorizontally)
            width: Math.ceil(implicitWidth * zoomableImage._scale)
            height: Math.ceil(implicitHeight * zoomableImage._scale)
            fillMode:  Image.PreserveAspectFit
            asynchronous: true
            clip: true
            anchors.centerIn: parent
            cache: true
            source: zoomableImage.imagePath
            onSourceChanged: {
                zoomableImage.scaled = false
            }
            onStatusChanged: {
                if (status === Image.Ready)
                    zoomableImage.read()
                else if (status === Image.Error) {
                    zoomableImage.setError(qsTr("Image error"), qsTr("Can't display strip"))
                }
            }

            opacity: status == Image.Ready ? 1 : 0
            Behavior on opacity { FadeAnimation{} }
        }
        AnimatedImage {
            id: largeComicImage
                width: 3264
                height: 3264
            cache: true
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
                if (mouseX - startX > Theme.startDragDistance && zoomableImage.atXBeginning
                        || mouseX - startX < -Theme.startDragDistance && zoomableImage.atXEnd) {
                    horizontalDragUnused = true
                } else if (mouseY - startY > Theme.startDragDistance && zoomableImage.atYBeginning
                           || mouseY - startY < -Theme.startDragDistance && zoomableImage.atYEnd) {

                    verticalDragUnused = true
                }
            }
            onClicked: zoomableImage.clicked()
            onDoubleClicked: {
                if (zoomableImage._scale !== zoomableImage._fittedScale) {
                    zoomOutAnimation.start()
                }
            }

            anchors.fill: parent

            ParallelAnimation {
                id: zoomOutAnimation
                SequentialAnimation {
                    NumberAnimation {
                        target: zoomableImage
                        property: "_scale"
                        to: zoomableImage._fittedScale
                        easing.type: Easing.InOutQuad
                        duration: 200
                    }
                    ScriptAction {
                        script: zoomableImage.scaled = false
                    }
                }
                NumberAnimation {
                    target: zoomableImage
                    properties: "contentX, contentY"
                    to: 0
                    easing.type: Easing.InOutQuad
                    duration: 200
                }
            }
        }
    }

    BusyIndicator {
        anchors.centerIn: parent
        running: comicImage.status === Image.Loading
        size: BusyIndicatorSize.Large
    }
}
