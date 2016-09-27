/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Lunch.h"

#include <QDebug>

Lunch::Lunch(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("lunch");
    m_info.name           = QString("Lunch");
    m_info.color          = QColor(171, 85, 148);
    m_info.authors        = QStringList("Børge Lund");
    m_info.homepage       = QUrl("http://www.lunchstriper.no/");
    m_info.country        = QLocale::Norway;
    m_info.language       = QLocale::Norwegian;
    m_info.stripSourceUrl = QUrl("http://www.dagbladet.no/tegneserie/lunch/");
}

QUrl Lunch::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/tegneserie/[^\"]*strip=lunch)\"");
}
