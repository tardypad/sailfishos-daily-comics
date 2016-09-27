/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Pigknit.h"

#include <QDebug>

Pigknit::Pigknit(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("pigknit");
    m_info.name           = QString("Pigknit");
    m_info.color          = QColor(199, 226, 221);
    m_info.authors        = QStringList("Jessie Miller");
    m_info.homepage       = QUrl("https://pigknit.wordpress.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("https://pigknit.wordpress.com/");
}

QUrl Pigknit::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*pigknit.files.wordpress.com[^\"]*)\"", 2);
}
