/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PearlsBeforeSwine.h"

#include <QDebug>

PearlsBeforeSwine::PearlsBeforeSwine(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("pearlsbeforeswine");
    m_info.name           = QString("Pearls Before Swine");
    m_info.color          = QColor(251, 192, 209);
    m_info.authors        = QStringList("Stephan Pastis");
    m_info.homepage       = QUrl("http://www.gocomics.com/pearlsbeforeswine");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2001-12-31", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/pearlsbeforeswine");
}

QUrl PearlsBeforeSwine::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
