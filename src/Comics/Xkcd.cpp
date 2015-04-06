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
}

const QString Xkcd::_id                 = QString("xkcd");
const QString Xkcd::_name               = QString("xkcd");
const QColor Xkcd::_color               = QColor(150, 168, 200);
const QStringList Xkcd::_authors        = QStringList("Randall Munroe");
const QUrl Xkcd::_homepage              = QUrl("http://xkcd.com/");
const QLocale::Country Xkcd::_country   = QLocale::UnitedStates;
const QLocale::Language Xkcd::_language = QLocale::English;
const QDate Xkcd::_startDate            = QDate::fromString("2005-09", "yyyy-MM");
const QDate Xkcd::_endDate              = QDate::currentDate();
const QUrl Xkcd::_stripSourceUrl        = QUrl("http://xkcd.com/info.0.json");

QUrl Xkcd::extractStripUrl(QByteArray data)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    QString src = jsonDoc.object().value("img").toString();

    return QUrl(src);
}
