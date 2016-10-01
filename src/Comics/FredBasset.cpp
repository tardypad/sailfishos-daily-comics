/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FredBasset.h"

#include <QDebug>

FredBasset::FredBasset(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("fredbasset");
}

QUrl FredBasset::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
