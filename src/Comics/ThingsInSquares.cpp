/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ThingsInSquares.h"

#include <QDebug>

ThingsInSquares::ThingsInSquares(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("thingsinsquares");
}

QUrl ThingsInSquares::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
