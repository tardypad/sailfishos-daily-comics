/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0
import Sailfish.Silica 1.0

Loader {
    id: loader
    active: _settings.settingsFavoritesInfoHint()
    anchors.fill: parent

    sourceComponent: Component {
        Item {
            anchors.fill: parent

            InteractionHintLabel {
                id: interactionHintLabel
                anchors.bottom: parent.bottom
                text: "Hold cover to display comic info"
                Behavior on opacity { FadeAnimation { duration: 1000 } }
                visible: opacity != 0

                MouseArea {
                    anchors.fill: parent
                    onPressed: closeHint()
                }

                Timer {
                    interval: 5000
                    running: true
                    onTriggered: closeHint()
                }
            }

            function closeHint() {
                _settings.hideSettingsFavoritesInfoHint()
                interactionHintLabel.opacity = 0.0
            }
        }
    }
}
