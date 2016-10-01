/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Dilbert.h"

#include <QDebug>

Dilbert::Dilbert(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("dilbert");
}

QUrl Dilbert::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*img-comic.*src=\"([^\"]*)\"");
}
