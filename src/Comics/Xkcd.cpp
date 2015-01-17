/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Xkcd.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Xkcd::Xkcd(QObject *parent) :
    Comic(parent)
{
}

const QString Xkcd::_id                 = QString("xkcd");
const QString Xkcd::_name               = QString("xkcd");
const QColor Xkcd::_color               = QColor(150, 168, 200);
const QString Xkcd::_author             = QString("Randall Munroe");
const QUrl Xkcd::_homepage              = QUrl("http://xkcd.com/");
const QLocale::Country Xkcd::_country   = QLocale::UnitedStates;
const QLocale::Language Xkcd::_language = QLocale::English;
const QDate Xkcd::_startDate            = QDate::fromString("2005-09", "yyyy-MM");
const QDate Xkcd::_endDate              = QDate::currentDate();
const QUrl Xkcd::_stripSourceUrl        = QUrl("http://xkcd.com/");

QUrl Xkcd::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/comics/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
