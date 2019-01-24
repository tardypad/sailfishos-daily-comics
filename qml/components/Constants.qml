/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

import QtQuick 2.0

QtObject {
    property string devMail: "damien@tardypad.me"
    property url devGithub: "https://github.com/tardypad"

    property string maintainerMail: "maledictusdemagog@gmail.com"
    property string maintainerGithub: "https://github.com/Maledictus"

    property url repoGithub: "https://github.com/tardypad/sailfishos-daily-comics"

    property string mailSubjectHeader: "[SailfishOS][Daily Comics " + Qt.application.version + "] "
    property string mailErrorSubjectHeader: "[SailfishOS][Daily Comics " + Qt.application.version + "][Error] "
    property string mailBodyHeader: "Yo man, "
}
