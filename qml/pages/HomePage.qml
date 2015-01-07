/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "../delegates"

Page {

    allowedOrientations: Orientation.All

    ListModel {
        id: comicModel
        ListElement {
            comicId: "calvinandhobbes"
            url:"http://assets.amuniversal.com/fdc547e04b3b0132acb2005056a9545d"
        }
        ListElement {
            comicId: "peanuts"
            url:"http://www.peanuts.com/wp-content/comic-strip/color-low-resolution/desktop/2015/daily/pe_c150107.jpg"
        }
        ListElement {
            comicId: "garfield"
            url:"http://assets.amuniversal.com/25f8ab6035fd0132a5ab005056a9545d"
        }
        ListElement {
            comicId: "xkcd"
            url:"http://imgs.xkcd.com/comics/worrying.png"
        }
        ListElement {
            comicId: "lechat"
            url:"http://geluck.com/dpics/strip/150107-9903019_FR.jpg"
        }
        ListElement {
            comicId: "dilbert"
            url:"http://www.dilbert.com/dyn/str_strip/000000000/00000000/0000000/200000/30000/6000/600/236663/236663.strip.gif"
        }
    }

    SilicaGridView {
        id: gridView

        property int cellSize: (orientation === Orientation.Portrait || orientation === Orientation.PortraitInverted)
                               ? parent.width / 2
                               : parent.width / 4

        anchors.fill: parent
        cellWidth: cellSize
        cellHeight: cellSize
        header: PageHeader {
            title: "Daily Comics"
        }
        delegate: ComicsGridDelegate { }
        model: comicModel

        function _goToComicPage(comicId, url) {
            pageStack.push(Qt.resolvedUrl("ComicPage.qml"), {"comicId": comicId, "url": url})
        }
    }

}


