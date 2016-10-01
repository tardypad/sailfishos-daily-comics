/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Swamp.h"

#include <QDebug>

Swamp::Swamp(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("swamp");
}

QUrl Swamp::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src='(strips/[^']*)'");
}
