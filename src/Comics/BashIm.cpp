/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "BashIm.h"

#include <QDebug>

BashIm::BashIm(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("bashim");
}

QUrl BashIm::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<div id=\"the_strip\"><img src=\"([^\"]*)\"");
}
