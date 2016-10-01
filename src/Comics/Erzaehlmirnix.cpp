/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Erzaehlmirnix.h"

#include <QDebug>

Erzaehlmirnix::Erzaehlmirnix(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("erzaehlmirnix");
}

QUrl Erzaehlmirnix::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*erzaehlmirnix.files.wordpress.com[^\"]*)\"", 2);
}
