/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "SarahsScribbles.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

SarahsScribbles::SarahsScribbles(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("sarahsscribbles");
    m_info.name           = QString("Sarah's Scribbles");
    m_info.color          = QColor(3, 193, 217);
    m_info.authors        = QStringList("Sarah Andersen");
    m_info.homepage       = QUrl("http://sarahcandersen.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2011-12-10", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://sarahcandersen.com/rss");
}

QUrl SarahsScribbles::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("&lt;img[^&]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
