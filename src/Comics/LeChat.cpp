/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LeChat.h"

LeChat::LeChat(QObject *parent) :
    Comic(parent)
{
}

const QString LeChat::_id     = QString("lechat");
const QString LeChat::_name   = QString("Le Chat");
const QString LeChat::_author = QString("Philippe Geluck");
const QUrl LeChat::_url       = QUrl("http://geluck.com/");
const QUrl LeChat::_stripUrl  = QUrl("http://geluck.com/dessin.html");
