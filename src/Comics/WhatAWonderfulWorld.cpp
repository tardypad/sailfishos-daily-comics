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
    m_info.id             = QString("whatawonderfulworld");
    m_info.name           = QString("What a wonderful world!");
    m_info.color          = QColor(195, 143, 189);
    m_info.authors        = QStringList("Philippe Chappuis \"Zep\"");
    m_info.homepage       = QUrl("http://zepworld.blog.lemonde.fr/");
    m_info.language       = QLocale::French;
    m_info.stripSourceUrl = QUrl("http://zepworld.blog.lemonde.fr/feed/atom/");
}

QUrl WhatAWonderfulWorld::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/files/[^\"]*)\"");
}
