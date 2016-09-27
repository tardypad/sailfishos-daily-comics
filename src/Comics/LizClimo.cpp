/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LizClimo.h"

#include <QDebug>

LizClimo::LizClimo(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("lizclimo");
    m_info.name           = QString("Liz Climo");
    m_info.color          = QColor(233, 142, 139);
    m_info.authors        = QStringList("Liz Climo");
    m_info.homepage       = QUrl("http://lizclimo.tumblr.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://lizclimo.tumblr.com/rss");
}

QUrl LizClimo::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "&lt;img[^&]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"");
}
