/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LizClimo.h"

#include <QDebug>

LizClimo::LizClimo(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("lizclimo");
}

QUrl LizClimo::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "&lt;img[^&]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"");
}
