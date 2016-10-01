/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Lunarbaboon.h"

#include <QDebug>

Lunarbaboon::Lunarbaboon(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("lunarbaboon");
}

QUrl Lunarbaboon::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(/storage/[^\"]*)\"");
}
