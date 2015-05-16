/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Lunarbaboon.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Lunarbaboon::Lunarbaboon(QObject *parent) :
    Comic(parent)
{
}

const QString Lunarbaboon::_id                 = QString("lunarbaboon");
const QString Lunarbaboon::_name               = QString("Lunarbaboon");
const QColor Lunarbaboon::_color               = QColor(197, 211, 221);
const QStringList Lunarbaboon::_authors        = QStringList("Chris Grady");
const QUrl Lunarbaboon::_homepage              = QUrl("http://www.lunarbaboon.com/");
const QLocale::Country Lunarbaboon::_country   = QLocale::Canada;
const QLocale::Language Lunarbaboon::_language = QLocale::English;
const QDate Lunarbaboon::_startDate            = QDate::fromString("2012-07-09", Qt::ISODate);
const QDate Lunarbaboon::_endDate              = QDate::currentDate();
const QUrl Lunarbaboon::_stripSourceUrl        = QUrl("http://www.lunarbaboon.com/");

QUrl Lunarbaboon::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(/storage/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://www.lunarbaboon.com/" + src);
}
