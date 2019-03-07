/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0
import Nemo.Notifications 1.0

import "pages"
import "cover"
import "components"

ApplicationWindow
{
    id: window

    allowedOrientations: Orientation.All

    initialPage: Component { FavoritesPage { } }
    cover: DefaultCover { }

    Constants {
        id: constants
    }

    Notification {
        id:notification
        appName: "Daily Comics"
    }

    function notify(text) {
        notification.previewBody = text
        notification.icon = "image://theme/icon-lock-information"
        notification.publish()
    }

    function showNewComicsPage() {
        var favoritesPage = pageStack.find(function(page) { return page.objectName === "FavoritesPage" })
        pageStack.pop(favoritesPage, PageStackAction.Immediate)
        pageStack.push(Qt.resolvedUrl("pages/NewComicsPage.qml"), {"comicsModel": favoritesPage.comicsModel}, PageStackAction.Immediate)
    }
}


