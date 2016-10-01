/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DrMcNinja.h"

#include <QDebug>

DrMcNinja::DrMcNinja(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("drmcninja");
}

QUrl DrMcNinja::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/comics/[^\"]*)\"");
}
