/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PearlsBeforeSwine.h"

#include <QDebug>

PearlsBeforeSwine::PearlsBeforeSwine(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("pearlsbeforeswine");
}

QUrl PearlsBeforeSwine::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
