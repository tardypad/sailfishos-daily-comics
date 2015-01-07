/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

BackgroundItem {
    width: gridView.cellWidth
    height: gridView.cellHeight

    Image {
        source: Qt.resolvedUrl("../../images/comics/"+comicId+".jpg")
        anchors.fill: parent
    }

    onClicked: gridView._goToComicPage(comicId, url)
}
