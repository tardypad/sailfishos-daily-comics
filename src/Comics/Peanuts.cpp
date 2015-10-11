/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Peanuts.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Peanuts::Peanuts(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("peanuts");
    m_info.name           = QString("Peanuts");
    m_info.color          = QColor(255, 223, 30);
    m_info.authors        = QStringList("Charles Monroe Schulz");
    m_info.homepage       = QUrl("http://www.peanuts.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1950-10-02", Qt::ISODate);
    m_info.endDate        = QDate::fromString("2000-02-13", Qt::ISODate);
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/peanuts/");
}

QUrl Peanuts::extractStripImageUrl(QByteArray data)
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
