/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "SadSacks.h"

#include <QDebug>

SadSacks::SadSacks(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("sadsacks");
}

QUrl SadSacks::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(images/comic/[^\"]*)\"");
}
