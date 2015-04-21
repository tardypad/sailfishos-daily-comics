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
}

const QString Smbc::_id                 = QString("smbc");
const QString Smbc::_name               = QString("Saturday Morning Breakfast Cereal");
const QColor Smbc::_color               = QColor(243, 255, 164);
const QStringList Smbc::_authors        = QStringList("Zach Weinersmith");
const QUrl Smbc::_homepage              = QUrl("http://www.smbc-comics.com/");
const QLocale::Country Smbc::_country   = QLocale::UnitedStates;
const QLocale::Language Smbc::_language = QLocale::English;
const QDate Smbc::_startDate            = QDate::fromString("2002-09-05", Qt::ISODate);
const QDate Smbc::_endDate              = QDate::currentDate();
const QUrl Smbc::_stripSourceUrl        = QUrl("http://www.smbc-comics.com/");

QUrl Smbc::extractStripUrl(QByteArray data)
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
