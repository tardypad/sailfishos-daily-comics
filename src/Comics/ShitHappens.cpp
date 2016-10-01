/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ShitHappens.h"

#include <QDebug>

ShitHappens::ShitHappens(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("shithappens");
}

QUrl ShitHappens::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/cartoons/[^\"]*)\"");
}
