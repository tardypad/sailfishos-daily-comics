/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0


Page {
    id: homePage

    allowedOrientations: Orientation.All

    Column {
        anchors.centerIn: parent
        spacing: Theme.paddingMedium

        Button {
            text: "View single image comic"
            onClicked: pageStack.push(Qt.resolvedUrl("ComicPage.qml"),
                                      {"url": "http://imgs.xkcd.com/comics/worrying.png"})
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            text: "View single strip comic"
            onClicked: pageStack.push(Qt.resolvedUrl("ComicPage.qml"),
                                      {"url": "http://assets.amuniversal.com/fdc547e04b3b0132acb2005056a9545d"})
            anchors.horizontalCenter: parent.horizontalCenter
        }

        Button {
            text: "View multiple strips comic"
            onClicked: pageStack.push(Qt.resolvedUrl("ComicPage.qml"),
                                      {"url": "http://assets.amuniversal.com/25f8ab6035fd0132a5ab005056a9545d"})
            anchors.horizontalCenter: parent.horizontalCenter
        }

    }

}


