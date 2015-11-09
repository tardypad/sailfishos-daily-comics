/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

import "../scripts/ExternalLinks.js" as ExternalLinks

Loader {
    id: loader

    property string comicName
    property Item flickable

    sourceComponent: Component {
        Rectangle {
            color: Theme.rgba(Theme.highlightBackgroundColor, Theme.highlightBackgroundOpacity / 3)
            x: flickable.originX + flickable.width - (width + Theme.paddingLarge)
            y: flickable.originY + flickable.height - (height + Theme.paddingLarge)
            width: devLabel.width + mailButton.width + 3*Theme.paddingSmall
            height: devLabel.height + 2*Theme.paddingSmall

            Label {
                id: devLabel
                anchors {
                    top: parent.top
                    topMargin: Theme.paddingSmall
                    left: parent.left
                    leftMargin: Theme.paddingSmall
                }
                text: "Please contact me\nif the problem persists.\nUse the comic homepage\nto read the strip for now."
                font.pixelSize: Theme.fontSizeExtraSmall
            }

            IconButton {
                id: mailButton
                height: Theme.iconSizeMedium
                width: Theme.iconSizeMedium
                anchors {
                    left: devLabel.right
                    leftMargin: Theme.paddingSmall
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
                    var mailErrorMail    = constants.devMail
                    var mailErrorSubject = constants.mailErrorSubjectHeader
                    var mailErrorMessage = constants.mailBodyHeader + "There is a problem with comic \"" + encodeURIComponent(loader.comicName) + "\""
                    ExternalLinks.mail(mailErrorMail, mailErrorSubject, mailErrorMessage)
                }
            }
        }
    }
}
