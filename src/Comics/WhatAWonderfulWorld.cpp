/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "WhatAWonderfulWorld.h"

#include <QDebug>

WhatAWonderfulWorld::WhatAWonderfulWorld(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("whatawonderfulworld");
}

QUrl WhatAWonderfulWorld::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/files/[^\"]*)\"");
}
