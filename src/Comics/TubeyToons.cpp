/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TubeyToons.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

TubeyToons::TubeyToons(QObject *parent) :
    Comic(parent)
{
}

const QString TubeyToons::_id                 = QString("tubeytoons");
const QString TubeyToons::_name               = QString("Tubey Toons");
const QColor TubeyToons::_color               = QColor(254, 180, 64);
const QStringList TubeyToons::_authors        = QStringList() << "Tubey" << "Wamn";
const QUrl TubeyToons::_homepage              = QUrl("http://tubeytoons.com/");
const QLocale::Country TubeyToons::_country   = QLocale::UnitedStates;
const QLocale::Language TubeyToons::_language = QLocale::English;
const QDate TubeyToons::_startDate            = QDate::fromString("2013-01-01", Qt::ISODate);
const QDate TubeyToons::_endDate              = QDate::currentDate();
const QUrl TubeyToons::_stripSourceUrl        = QUrl("http://tubeytoons.com/");

QUrl TubeyToons::extractStripImageUrl(QByteArray data)
{
    QString html(data);

    QRegularExpression reg("<img[^>]*src=\'(.*/images/comics/[^\']*)\'");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
