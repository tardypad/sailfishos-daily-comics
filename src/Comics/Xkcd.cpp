/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Xkcd.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

Xkcd::Xkcd(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("xkcd");
    m_info.name           = QString("xkcd");
    m_info.color          = QColor(149, 168, 200);
    m_info.authors        = QStringList("Randall Munroe");
    m_info.homepage       = QUrl("http://xkcd.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2005-09", "yyyy-MM");
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://xkcd.com/info.0.json");
}

QUrl Xkcd::extractStripImageUrl(QByteArray data)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    QString src = jsonDoc.object().value("img").toString();

    return QUrl(src);
}
