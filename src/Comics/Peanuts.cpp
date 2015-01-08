/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Peanuts.h"

Peanuts::Peanuts(QObject *parent) :
    Comic(parent)
{
}

const QString Peanuts::_id          = QString("peanuts");
const QString Peanuts::_name        = QString("Peanuts");
const QString Peanuts::_author      = QString("Charles Monroe Schulz");
const QUrl Peanuts::_homepage       = QUrl("http://www.peanuts.com/");
const QUrl Peanuts::_stripSourceUrl = QUrl("http://www.peanuts.com/comics/");

QUrl Peanuts::extractStripUrl(QByteArray data)
{
    return QUrl("http://www.peanuts.com/wp-content/comic-strip/color-low-resolution/desktop/2015/daily/pe_c150107.jpg");
}
