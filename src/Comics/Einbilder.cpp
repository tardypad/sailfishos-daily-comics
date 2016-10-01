/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Einbilder.h"

#include <QDebug>

Einbilder::Einbilder(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("einbilder");
}

QUrl Einbilder::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(images/cartoons/[^\"]*)\"");
}
