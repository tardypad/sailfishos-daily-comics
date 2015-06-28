/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PirateMike.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

PirateMike::PirateMike(QObject *parent) :
    Comic(parent)
{
}

const QString PirateMike::_id                 = QString("piratemike");
const QString PirateMike::_name               = QString("Pirate Mike");
const QColor PirateMike::_color               = QColor(255, 71, 33);
const QStringList PirateMike::_authors        = QStringList("Brad Perri");
const QUrl PirateMike::_homepage              = QUrl("http://piratemikecomics.com/");
const QLocale::Country PirateMike::_country   = QLocale::UnitedStates;
const QLocale::Language PirateMike::_language = QLocale::English;
const QDate PirateMike::_startDate            = QDate::fromString("2012-04-04", Qt::ISODate);
const QDate PirateMike::_endDate              = QDate::currentDate();
const QUrl PirateMike::_stripSourceUrl        = QUrl("http://piratemikecomics.com/");

QUrl PirateMike::extractStripImageUrl(QByteArray data)
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
