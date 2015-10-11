/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "MacadamValley.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

MacadamValley::MacadamValley(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("macadamvalley");
    m_info.name           = QString("Macadam Valley");
    m_info.color          = QColor(185, 167, 131);
    m_info.authors        = QStringList("Ben Dessy");
    m_info.homepage       = QUrl("http://macadamvalley.com/");
    m_info.country        = QLocale::France;
    m_info.language       = QLocale::French;
    m_info.startDate      = QDate::fromString("2012-01-23", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://macadamvalley.com/feed/");
}

QUrl MacadamValley::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
