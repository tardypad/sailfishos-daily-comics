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
}

const QString Garfield::_id                 = QString("garfield");
const QString Garfield::_name               = QString("Garfield");
const QString Garfield::_author             = QString("Jim Davis");
const QUrl Garfield::_homepage              = QUrl("http://garfield.com/");
const QLocale::Country Garfield::_country   = QLocale::UnitedStates;
const QLocale::Language Garfield::_language = QLocale::English;
const QDate Garfield::_startDate            = QDate::fromString("1978-06-19", Qt::ISODate);
const QDate Garfield::_endDate              = QDate::currentDate();
const QUrl Garfield::_stripSourceUrl        = QUrl("http://garfield.com/");

QUrl Garfield::extractStripUrl(QByteArray data)
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
