/**
 * Copyright (c) 2015 Damien Tardy-Panis
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

Page {
    id: comicPage

    allowedOrientations: Orientation.All

    property int index
    property ComicsModel comicsModel

    ComicProxy {
        id: comicProxy

        onIdChanged: {
            comicViewLoader.source = comicProxy.animated ?
                    "../components/AnimatedComicItem.qml" :
                    "../components/ImageComicItem.qml"
        }
    }

    Loader {
        id: comicViewLoader
        anchors.fill: parent
        active: source !== ""
        asynchronous: true
        visible: status == Loader.Ready

        property var comic: comicProxy
        property int index: comicPage.index
        property ComicsModel model: comicPage.comicsModel
    }

    Component.onCompleted: {
        comicProxy.setComic(comicsModel.comicAt(index))
        comicProxy.fetch()
    }
}
