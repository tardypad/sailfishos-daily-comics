/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "MacadamValley.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

MacadamValley::MacadamValley(QObject *parent) :
    Comic(parent)
{
}

const QString MacadamValley::_id                 = QString("macadamvalley");
const QString MacadamValley::_name               = QString("Macadam Valley");
const QColor MacadamValley::_color               = QColor(174, 166, 117);
const QStringList MacadamValley::_authors        = QStringList("Ben Dessy");
const QUrl MacadamValley::_homepage              = QUrl("http://macadamvalley.com/");
const QLocale::Country MacadamValley::_country   = QLocale::France;
const QLocale::Language MacadamValley::_language = QLocale::French;
const QDate MacadamValley::_startDate            = QDate::fromString("2012-01-23", Qt::ISODate);
const QDate MacadamValley::_endDate              = QDate::currentDate();
const QUrl MacadamValley::_stripSourceUrl        = QUrl("http://macadamvalley.com/feed/");

QUrl MacadamValley::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
