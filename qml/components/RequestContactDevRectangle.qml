/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "../scripts/ExternalLinks.js" as ExternalLinks

Item {

    property Item flickable

    width: flickable.width
    height: rect.height + 2*Theme.paddingLarge

    Rectangle {
        id: rect

        width: parent.width
        height: label.height + 2*Theme.paddingSmall
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
        anchors.margins: Theme.paddingLarge

        color: Theme.rgba(Theme.highlightBackgroundColor, Theme.highlightBackgroundOpacity / 3)

        Label {
            id: label
            anchors {
                left: parent.left
                leftMargin: Theme.paddingSmall
                verticalCenter: parent.verticalCenter
            }
            width: parent.width - mailButton.width - 3*Theme.paddingSmall
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            text: qsTr("Let me know if you're missing some of your favorite comics in this list")
            font.pixelSize: Theme.fontSizeExtraSmall
        }

        IconButton {
            id: mailButton
            height: Theme.iconSizeMedium
            width: Theme.iconSizeMedium
            anchors {
                left: label.right
                leftMargin: Theme.paddingSmall
                rightMargin: Theme.paddingSmall
                verticalCenter: parent.verticalCenter
            }
            icon {
                source: "image://theme/icon-m-mail"
                height: Theme.iconSizeMedium
                fillMode: Image.PreserveAspectFit
            }
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                var mailRequestMail    = constants.devMail
                var mailRequestSubject = constants.mailSubjectHeader
                var mailRequestMessage = constants.mailBodyHeader + "Please add these comics to the app: "
                ExternalLinks.mail(mailRequestMail, mailRequestSubject, mailRequestMessage)
            }
        }
    }
}
