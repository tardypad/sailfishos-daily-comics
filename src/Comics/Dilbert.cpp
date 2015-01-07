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

const QString Dilbert::_id     = QString("dilbert");
const QString Dilbert::_name   = QString("Dilbert");
const QString Dilbert::_author = QString("Scott Adams");
const QUrl Dilbert::_url       = QUrl("http://www.dilbert.com/");
const QUrl Dilbert::_stripUrl  = QUrl("http://www.dilbert.com/strips/");
