/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "BerkeleyMews.h"

#include <QDebug>

BerkeleyMews::BerkeleyMews(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("berkeleymews");
}

QUrl BerkeleyMews::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/comics/[^\"]*)\"", 2);
}
