/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheBoondocks.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

TheBoondocks::TheBoondocks(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("theboondocks");
    m_info.name           = QString("The Boondocks");
    m_info.color          = QColor(175, 121, 83);
    m_info.authors        = QStringList("Aaron McGruder");
    m_info.homepage       = QUrl("http://www.gocomics.com/boondocks");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1996-04-19", Qt::ISODate);
    m_info.endDate        = QDate::fromString("2006-03-26", Qt::ISODate);
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/boondocks");
}

QUrl TheBoondocks::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
