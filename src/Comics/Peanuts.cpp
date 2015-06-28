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
}

const QString Peanuts::_id                 = QString("peanuts");
const QString Peanuts::_name               = QString("Peanuts");
const QColor Peanuts::_color               = QColor(133, 248, 255);
const QStringList Peanuts::_authors        = QStringList("Charles Monroe Schulz");
const QUrl Peanuts::_homepage              = QUrl("http://www.peanuts.com/");
const QLocale::Country Peanuts::_country   = QLocale::UnitedStates;
const QLocale::Language Peanuts::_language = QLocale::English;
const QDate Peanuts::_startDate            = QDate::fromString("1950-10-02", Qt::ISODate);
const QDate Peanuts::_endDate              = QDate::fromString("2000-02-13", Qt::ISODate);
const QUrl Peanuts::_stripSourceUrl        = QUrl("http://www.gocomics.com/peanuts/");

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
