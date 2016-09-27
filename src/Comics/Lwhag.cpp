/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Lwhag.h"

#include <QDebug>

Lwhag::Lwhag(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("lwhag");
    m_info.name           = QString("Living with Hipstergirl and Gamergirl");
    m_info.color          = QColor(169, 99, 169);
    m_info.authors        = QStringList("Jago Dibuja");
    m_info.homepage       = QUrl("http://www.jagodibuja.com/webcomic-living-with-hipstergirl-and-gamergirl-english/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.jagodibuja.com/feed/");
}

QUrl Lwhag::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*)\"[^>]*alt=\"[^\"]*english\"");
}
