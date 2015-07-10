/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FredBasset.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

FredBasset::FredBasset(QObject *parent) :
    Comic(parent)
{
}

const QString FredBasset::_id                 = QString("fredbasset");
const QString FredBasset::_name               = QString("Fred Basset");
const QColor FredBasset::_color               = QColor(205, 178, 61);
const QStringList FredBasset::_authors        = QStringList() << "Alex Graham" << "Michael Martin";
const QUrl FredBasset::_homepage              = QUrl("http://www.gocomics.com/fredbasset/");
const QLocale::Country FredBasset::_country   = QLocale::UnitedKingdom;
const QLocale::Language FredBasset::_language = QLocale::English;
const QDate FredBasset::_startDate            = QDate::fromString("1963-07-08", Qt::ISODate);
const QDate FredBasset::_endDate              = QDate::currentDate();
const QUrl FredBasset::_stripSourceUrl        = QUrl("http://www.gocomics.com/fredbasset/");

QUrl FredBasset::extractStripImageUrl(QByteArray data)
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
