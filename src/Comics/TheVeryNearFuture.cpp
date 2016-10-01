/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheVeryNearFuture.h"

#include <QDebug>

TheVeryNearFuture::TheVeryNearFuture(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("theverynearfuture");
}

QUrl TheVeryNearFuture::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "&lt;img[^&]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"");
}
