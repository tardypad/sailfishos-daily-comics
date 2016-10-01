/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FokIt.h"

#include <QDebug>

FokIt::FokIt(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("fokit");
}

QUrl FokIt::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/webkuva/sarjis[^\"]*)\"");
}
