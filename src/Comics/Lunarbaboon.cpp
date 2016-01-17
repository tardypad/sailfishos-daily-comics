/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Lunarbaboon.h"

#include <QDebug>

Lunarbaboon::Lunarbaboon(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("lunarbaboon");
    m_info.name           = QString("Lunarbaboon");
    m_info.color          = QColor(205, 207, 206);
    m_info.authors        = QStringList("Chris Grady");
    m_info.homepage       = QUrl("http://www.lunarbaboon.com/");
    m_info.country        = QLocale::Canada;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2012-07-09", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.lunarbaboon.com/");
}

QUrl Lunarbaboon::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(/storage/[^\"]*)\"");
}
