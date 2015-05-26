/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import harbour.dailycomics.Comics 1.0

CoverBackground {

    property ComicsModel comicsModel
    property bool emptyComics: !comicsModel || comicsModel.count == 0

    GridView {
        id: grid
        anchors.fill: parent
        interactive: false
        cellWidth: Math.floor(width / 2.0)
        cellHeight: Math.ceil(height / 3.0)
        model: comicsModel

        delegate: Image {
            source: Qt.resolvedUrl("../../images/comics/covers/"+id+".jpg")
            width: grid.cellWidth
            height: grid.cellHeight
            sourceSize.width: width
            sourceSize.height: height
        }
    }

    Column {
        visible: emptyComics
        spacing: Theme.paddingLarge

        anchors.centerIn: parent

        Label {
            text: "Daily Comics"
            color: Theme.highlightColor
        }

        Image {
            fillMode: Image.PreserveAspectFit
            source: "../../images/cover.png"
            opacity: 0.6
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

}
