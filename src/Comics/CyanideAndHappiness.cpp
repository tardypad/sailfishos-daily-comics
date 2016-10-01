/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "CyanideAndHappiness.h"

#include <QDebug>

CyanideAndHappiness::CyanideAndHappiness(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("cyanideandhappiness");
}

QUrl CyanideAndHappiness::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/comics/[^\"]*)\"");
}
