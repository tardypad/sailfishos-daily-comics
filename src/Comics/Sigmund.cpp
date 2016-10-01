/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Sigmund.h"

#include <QDebug>

Sigmund::Sigmund(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("sigmund");
}

QUrl Sigmund::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=(strips/[^ ]*) ");
}
