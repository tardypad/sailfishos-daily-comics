/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "BeetleBailey.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

BeetleBailey::BeetleBailey(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("beetlebailey");
    m_info.name           = QString("Beetle Bailey");
    m_info.color          = QColor(174, 169, 137);
    m_info.authors        = QStringList("Mort Walker");
    m_info.homepage       = QUrl("http://beetlebailey.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1950-09-04", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://beetlebailey.com/");
}

QUrl BeetleBailey::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<meta property=\"og:image\" content=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
