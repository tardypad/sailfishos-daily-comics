/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Smbc.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Smbc::Smbc(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("smbc");
    m_info.name           = QString("Saturday Morning Breakfast Cereal");
    m_info.color          = QColor(81, 106, 146);
    m_info.authors        = QStringList("Zach Weinersmith");
    m_info.homepage       = QUrl("http://www.smbc-comics.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2002-09-05", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.smbc-comics.com/");
}

QUrl Smbc::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*)\" id=\"comic\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://www.smbc-comics.com/" + src);
}
