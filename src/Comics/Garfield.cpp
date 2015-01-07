/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Garfield.h"

Garfield::Garfield(QObject *parent) :
    Comic(parent)
{
}

const QString Garfield::_id     = QString("garfield");
const QString Garfield::_name   = QString("Garfield");
const QString Garfield::_author = QString("Jim Davis");
const QUrl Garfield::_url       = QUrl("http://garfield.com/");
const QUrl Garfield::_stripUrl  = QUrl("http://garfield.com/comic/");
