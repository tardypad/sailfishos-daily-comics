/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Pigknit.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Pigknit::Pigknit(QObject *parent) :
    Comic(parent)
{
}

const QString Pigknit::_id                 = QString("pigknit");
const QString Pigknit::_name               = QString("Pigknit");
const QColor Pigknit::_color               = QColor(190, 175, 208);
const QStringList Pigknit::_authors        = QStringList("Jessie Miller");
const QUrl Pigknit::_homepage              = QUrl("https://pigknit.wordpress.com/");
const QLocale::Country Pigknit::_country   = QLocale::UnitedStates;
const QLocale::Language Pigknit::_language = QLocale::English;
const QDate Pigknit::_startDate            = QDate::fromString("2014-10-28", Qt::ISODate);
const QDate Pigknit::_endDate              = QDate::currentDate();
const QUrl Pigknit::_stripSourceUrl        = QUrl("https://pigknit.wordpress.com/");

QUrl Pigknit::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*pigknit.files.wordpress.com[^\"]*)\"");
    QRegularExpressionMatchIterator matchIterator = reg.globalMatch(html);

    if (!matchIterator.hasNext())
        return QUrl();

    matchIterator.next();

    if (!matchIterator.hasNext())
        return QUrl();

    QRegularExpressionMatch match = matchIterator.next();

    QString src = match.captured(1);

    return QUrl(src);
}
