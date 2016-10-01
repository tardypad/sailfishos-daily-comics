/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "BloomCounty2015.h"

#include <QDebug>

BloomCounty2015::BloomCounty2015(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("bloomcounty2015");
}

QUrl BloomCounty2015::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
