/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FokIt.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

FokIt::FokIt(QObject *parent) :
    Comic(parent)
{
}

const QString FokIt::_id                 = QString("fokit");
const QString FokIt::_name               = QString("Fok_it");
const QColor FokIt::_color               = QColor(255, 138, 145);
const QStringList FokIt::_authors        = QStringList("Joonas Rinta-Kanto");
const QUrl FokIt::_homepage              = QUrl("https://fokit.wordpress.com/");
const QLocale::Country FokIt::_country   = QLocale::Finland;
const QLocale::Language FokIt::_language = QLocale::Finnish;
const QDate FokIt::_startDate            = QDate::fromString("2009", "yyyy");
const QDate FokIt::_endDate              = QDate::currentDate();
const QUrl FokIt::_stripSourceUrl        = QUrl("http://nyt.fi/aihe/fokit/");

QUrl FokIt::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/webkuva/sarjis[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
