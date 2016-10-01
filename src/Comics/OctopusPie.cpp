/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "OctopusPie.h"

#include <QDebug>

OctopusPie::OctopusPie(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("octopuspie");
}

QUrl OctopusPie::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/strippy/[^\"]*)\"");
}
