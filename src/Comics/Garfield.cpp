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

const QString Garfield::_id          = QString("garfield");
const QString Garfield::_name        = QString("Garfield");
const QString Garfield::_author      = QString("Jim Davis");
const QUrl Garfield::_homepage       = QUrl("http://garfield.com/");
const QUrl Garfield::_stripSourceUrl = QUrl("http://garfield.com/comic/");

QUrl Garfield::extractStripUrl()
{
    return QUrl("http://assets.amuniversal.com/25f8ab6035fd0132a5ab005056a9545d");
}
