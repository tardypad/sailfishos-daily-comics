/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "BerkeleyMews.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

BerkeleyMews::BerkeleyMews(QObject *parent) :
    Comic(parent)
{
}

const QString BerkeleyMews::_id                 = QString("berkeleymews");
const QString BerkeleyMews::_name               = QString("Berkeley Mews");
const QColor BerkeleyMews::_color               = QColor(237, 233, 195);
const QStringList BerkeleyMews::_authors        = QStringList("Ben Zaehringer");
const QUrl BerkeleyMews::_homepage              = QUrl("http://www.berkeleymews.com/");
const QLocale::Country BerkeleyMews::_country   = QLocale::UnitedStates;
const QLocale::Language BerkeleyMews::_language = QLocale::English;
const QDate BerkeleyMews::_startDate            = QDate::fromString("2009-12-27", Qt::ISODate);
const QDate BerkeleyMews::_endDate              = QDate::currentDate();
const QUrl BerkeleyMews::_stripSourceUrl        = QUrl("http://www.berkeleymews.com/");

QUrl BerkeleyMews::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*/comics/[^\"]*)\"");
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
