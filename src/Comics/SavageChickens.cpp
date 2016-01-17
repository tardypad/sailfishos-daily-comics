/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "SavageChickens.h"

#include <QDebug>

SavageChickens::SavageChickens(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("savagechickens");
    m_info.name           = QString("Savage Chickens");
    m_info.color          = QColor(255, 251, 167);
    m_info.authors        = QStringList("Doug Savage");
    m_info.homepage       = QUrl("http://www.savagechickens.com/");
    m_info.country        = QLocale::Canada;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2005-01-31", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.savagechickens.com/feed");
}

QUrl SavageChickens::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
