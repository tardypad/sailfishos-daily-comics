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
    active: _settings.newSlideshowFlickHint()
    anchors.fill: parent

    sourceComponent: Component {
        Item {
            anchors.fill: parent

            function startAnimation() {
                touchInteractionHint.start()
            }

            InteractionHintLabel {
                id: interactionHintLabel
                anchors.bottom: parent.bottom
                text: "Flick to display next comic"
                Behavior on opacity { FadeAnimation { duration: 1000 } }
                opacity: touchInteractionHint.running ? 1.0 : 0.0
            }

            TouchInteractionHint {
                id: touchInteractionHint
                direction: TouchInteraction.Left
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    onStatusChanged: {
        if (status == Loader.Ready) {
            loader.item.startAnimation()
            _settings.hideNewSlideshowFlickHint()
        }
    }
}
