/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Lunch.h"

#include <QDebug>

Lunch::Lunch(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("lunch");
}

QUrl Lunch::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/tegneserie/[^\"]*strip=lunch)\"");
}
