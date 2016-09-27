/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "JaatavaSpede.h"

#include <QDebug>

JaatavaSpede::JaatavaSpede(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("jaatavaspede");
    m_info.name           = QString("Jäätävä Spede");
    m_info.color          = QColor(246, 94, 47);
    m_info.authors        = QStringList("Pertti Jarla");
    m_info.homepage       = QUrl("http://www.hs.fi/jaatavaspede/");
    m_info.country        = QLocale::Finland;
    m_info.language       = QLocale::Finnish;
    m_info.stripSourceUrl = QUrl("http://www.hs.fi/jaatavaspede/");
}

QUrl JaatavaSpede::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/webkuva/[^\"]*)\"", 2);
}
