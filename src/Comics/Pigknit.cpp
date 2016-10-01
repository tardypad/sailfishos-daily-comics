/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Pigknit.h"

#include <QDebug>

Pigknit::Pigknit(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("pigknit");
}

QUrl Pigknit::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*pigknit.files.wordpress.com[^\"]*)\"", 2);
}
