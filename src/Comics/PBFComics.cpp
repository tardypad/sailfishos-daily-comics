/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PBFComics.h"

#include <QDebug>

PBFComics::PBFComics(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("pbfcomics");
    m_info.name           = QString("The Perry Bible Fellowship");
    m_info.color          = QColor(216, 11, 16);
    m_info.authors        = QStringList("Nicholas Gurewitch");
    m_info.homepage       = QUrl("http://pbfcomics.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://pbfcomics.com/feed/feed.xml");
}

QUrl PBFComics::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "src=&quot;([^&]*/archive_b/[^&]*)&quot;");
}
