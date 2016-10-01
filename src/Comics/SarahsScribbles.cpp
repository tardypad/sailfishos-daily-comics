/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "SarahsScribbles.h"

#include <QDebug>

SarahsScribbles::SarahsScribbles(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("sarahsscribbles");
}

QUrl SarahsScribbles::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "&lt;img[^&]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"");
}
