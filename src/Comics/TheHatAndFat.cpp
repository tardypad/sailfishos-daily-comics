/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheHatAndFat.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

TheHatAndFat::TheHatAndFat(QObject *parent) :
    Comic(parent)
{
}

const QString TheHatAndFat::_id                 = QString("thehatandfat");
const QString TheHatAndFat::_name               = QString("The Hat and Fat");
const QColor TheHatAndFat::_color               = QColor(102, 102, 102);
const QStringList TheHatAndFat::_authors        = QStringList() << "Eric Crowe" << "Dusty Perdue";
const QUrl TheHatAndFat::_homepage              = QUrl("https://thehatandfat.wordpress.com/");
const QLocale::Country TheHatAndFat::_country   = QLocale::UnitedStates;
const QLocale::Language TheHatAndFat::_language = QLocale::English;
const QDate TheHatAndFat::_startDate            = QDate::fromString("2013-02", "yyyy-MM");
const QDate TheHatAndFat::_endDate              = QDate::currentDate();
const QUrl TheHatAndFat::_stripSourceUrl        = QUrl("https://thehatandfat.wordpress.com/");

QUrl TheHatAndFat::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(https://thehatandfat.files.wordpress.com/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
