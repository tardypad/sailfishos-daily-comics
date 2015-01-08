/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Dilbert.h"

Dilbert::Dilbert(QObject *parent) :
    Comic(parent)
{
}

const QString Dilbert::_id          = QString("dilbert");
const QString Dilbert::_name        = QString("Dilbert");
const QString Dilbert::_author      = QString("Scott Adams");
const QUrl Dilbert::_homepage       = QUrl("http://www.dilbert.com/");
const QUrl Dilbert::_stripSourceUrl = QUrl("http://www.dilbert.com/strips/");

QUrl Dilbert::extractStripUrl(QByteArray data)
{
    return QUrl("http://www.dilbert.com/dyn/str_strip/000000000/00000000/0000000/200000/30000/6000/600/236663/236663.strip.gif");
}
