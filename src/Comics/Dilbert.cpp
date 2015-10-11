/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Dilbert.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Dilbert::Dilbert(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("dilbert");
    m_info.name           = QString("Dilbert");
    m_info.color          = QColor(239, 58, 67);
    m_info.authors        = QStringList("Scott Adams");
    m_info.homepage       = QUrl("http://dilbert.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1989-04-16", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://dilbert.com/");
}

QUrl Dilbert::extractStripImageUrl(QByteArray data)
{
    QString html(data);

    QRegularExpression reg("<img[^>]*img-comic.*src=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
