/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "CCassandra.h"

#include <QDebug>

CCassandra::CCassandra(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("ccassandra");
    m_info.name           = QString("C. Cassandra");
    m_info.color          = QColor(186, 186, 186);
    m_info.authors        = QStringList("Cassandra Calin");
    m_info.homepage       = QUrl("http://c-cassandra.tumblr.com/");
    m_info.country        = QLocale::Canada;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://c-cassandra.tumblr.com/rss");
}

QUrl CCassandra::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "&lt;img[^&]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"");
}
