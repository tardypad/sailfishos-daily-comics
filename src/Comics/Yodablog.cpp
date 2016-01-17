/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Yodablog.h"

#include <QDebug>

Yodablog::Yodablog(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("yodablog");
    m_info.name           = QString("Yodablog");
    m_info.color          = QColor(154, 183, 93);
    m_info.authors        = QStringList("Thierry Vivien");
    m_info.homepage       = QUrl("http://www.yodablog.net/");
    m_info.country        = QLocale::France;
    m_info.language       = QLocale::French;
    m_info.startDate      = QDate::fromString("2009-01-01", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.yodablog.net/?feed=rss2");
}

QUrl Yodablog::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
