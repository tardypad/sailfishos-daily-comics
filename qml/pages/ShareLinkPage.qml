/**
 * Copyright (c) 2018-2019 Oleg Linkin <maledictusdemagog@gmail.com>
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/


import QtQuick 2.0
import Sailfish.Silica 1.0
import Sailfish.TransferEngine 1.0

Page {
    id: shareLinkPage

    property string link
    property string linkTitle

    ShareMethodList {
        id: shareMethodList
        anchors.fill: parent
        header: PageHeader {
            title: qsTr("Share comics link")
        }
        filter: "text/x-url"
        content: {
            "type": "text/x-url",
            "status": shareLinkPage.link,
            "linkTitle": shareLinkPage.linkTitle
        }

        ViewPlaceholder {
            enabled: shareMethodList.model.count === 0 && shareMethodList.model.ready
            text: qsTr("No sharing accounts available. You can add accounts in settings")
        }
    }
}
