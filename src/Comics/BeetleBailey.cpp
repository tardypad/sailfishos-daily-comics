/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "BeetleBailey.h"

#include <QDebug>

BeetleBailey::BeetleBailey(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("beetlebailey");
}

QUrl BeetleBailey::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<meta property=\"og:image\" content=\"([^\"]*)\"");
}
