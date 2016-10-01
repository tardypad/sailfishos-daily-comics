/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ExtraOrdinary.h"

#include <QDebug>

ExtraOrdinary::ExtraOrdinary(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("extraordinary");
}

QUrl ExtraOrdinary::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/comics/comics/[^\"]*)\"");
}
