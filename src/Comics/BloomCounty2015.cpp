/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "BloomCounty2015.h"

#include <QDebug>

BloomCounty2015::BloomCounty2015(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("bloomcounty2015");
    m_info.name           = QString("Bloom County 2015");
    m_info.color          = QColor(190, 154, 224);
    m_info.authors        = QStringList("Berkeley Breathed");
    m_info.homepage       = QUrl("http://www.berkeleybreathed.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/bloom-county");
}

QUrl BloomCounty2015::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
