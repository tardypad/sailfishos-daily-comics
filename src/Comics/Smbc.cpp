/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Smbc.h"

#include <QDebug>

Smbc::Smbc(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("smbc");
}

QUrl Smbc::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*)\" id=\"cc-comic\"");
}
