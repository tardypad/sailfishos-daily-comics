/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ThingsInSquares.h"

#include <QDebug>

ThingsInSquares::ThingsInSquares(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("thingsinsquares");
    m_info.name           = QString("Things in Squares");
    m_info.color          = QColor(176, 242, 180);
    m_info.authors        = QStringList("Cale");
    m_info.homepage       = QUrl("http://www.thingsinsquares.com/");
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2014-03", "yyyy-MM");
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://feeds.feedburner.com/ThingsInSquares?format=xml");
}

QUrl ThingsInSquares::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
