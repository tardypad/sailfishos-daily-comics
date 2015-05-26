/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "pages"
import "cover"

ApplicationWindow
{
    id: window

    allowedOrientations: Orientation.Portrait | Orientation.Landscape | Orientation.LandscapeInverted

    initialPage: Component { FavoritesPage { } }
    cover: DefaultCover { }

    function showNewComicsPage() {
        var favoritesPage = pageStack.find(function(page) { return page.objectName === "FavoritesPage" })
        pageStack.pop(favoritesPage, PageStackAction.Immediate)
        pageStack.push(Qt.resolvedUrl("pages/NewComicsPage.qml"), {"comicsModel": favoritesPage.comicsModel}, PageStackAction.Immediate)
    }
}


