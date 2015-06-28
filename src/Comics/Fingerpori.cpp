/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Fingerpori.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Fingerpori::Fingerpori(QObject *parent) :
    Comic(parent)
{
}

const QString Fingerpori::_id                 = QString("fingerpori");
const QString Fingerpori::_name               = QString("Fingerpori");
const QColor Fingerpori::_color               = QColor(148, 8, 11);
const QStringList Fingerpori::_authors        = QStringList("Pertti Jarla");
const QUrl Fingerpori::_homepage              = QUrl("http://fingerpori.org");
const QLocale::Country Fingerpori::_country   = QLocale::Finland;
const QLocale::Language Fingerpori::_language = QLocale::Finnish;
const QDate Fingerpori::_startDate            = QDate::fromString("2007-02", "yyyy-MM");
const QDate Fingerpori::_endDate              = QDate::currentDate();
const QUrl Fingerpori::_stripSourceUrl        = QUrl("http://www.hs.fi/m/fingerpori/");

QUrl Fingerpori::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/webkuva/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
