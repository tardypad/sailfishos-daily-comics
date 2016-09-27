/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Ahistaa.h"

#include <QDebug>

Ahistaa::Ahistaa(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("ahistaa");
    m_info.name           = QString("Ahistaa");
    m_info.color          = QColor(177, 177, 177);
    m_info.authors        = QStringList("Kris K");
    m_info.homepage       = QUrl("http://ahistaa.tumblr.com/");
    m_info.language       = QLocale::Finnish;
    m_info.stripSourceUrl = QUrl("http://ahistaa.tumblr.com/rss");
}

QUrl Ahistaa::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "&lt;img[^&]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"");
}
