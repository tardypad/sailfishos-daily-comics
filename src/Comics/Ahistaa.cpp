/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Ahistaa.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Ahistaa::Ahistaa(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("ahistaa");
    m_info.name           = QString("Ahistaa");
    m_info.color          = QColor(177, 177, 177);
    m_info.authors        = QStringList("Kris K");
    m_info.homepage       = QUrl("http://ahistaa.sarjakuvablogit.com/");
    m_info.country        = QLocale::Finland;
    m_info.language       = QLocale::Finnish;
    m_info.startDate      = QDate::fromString("2014-11-05", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://ahistaa.sarjakuvablogit.com/feed/");
}

QUrl Ahistaa::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
