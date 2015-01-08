/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "CalvinAndHobbes.h"

CalvinAndHobbes::CalvinAndHobbes(QObject *parent) :
    Comic(parent)
{
}

const QString CalvinAndHobbes::_id     = QString("calvinandhobbes");
const QString CalvinAndHobbes::_name   = QString("Calvin and Hobbes");
const QString CalvinAndHobbes::_author = QString("Bill Watterson");
const QUrl CalvinAndHobbes::_url       = QUrl("http://www.gocomics.com/calvinandhobbes/");
const QUrl CalvinAndHobbes::_stripUrl  = QUrl("http://www.gocomics.com/calvinandhobbes/");

QUrl CalvinAndHobbes::getCurrentStripUrl()
{
    return QUrl("http://assets.amuniversal.com/fdc547e04b3b0132acb2005056a9545d");
}
