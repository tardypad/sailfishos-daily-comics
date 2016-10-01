/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Gwtb.h"

#include <QDebug>

Gwtb::Gwtb(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("gwtb");
}

QUrl Gwtb::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(./comics/[^\"]*)\"");
}
