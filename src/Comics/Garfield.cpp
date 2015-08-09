/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Garfield.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Garfield::Garfield(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("garfield");
    m_info.name           = QString("Garfield");
    m_info.color          = QColor(236, 197, 57);
    m_info.authors        = QStringList("Jim Davis");
    m_info.homepage       = QUrl("http://garfield.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1978-06-19", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://garfield.com/");
}

QUrl Garfield::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/strips/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
