/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheAwkwardYeti.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

TheAwkwardYeti::TheAwkwardYeti(QObject *parent) :
    Comic(parent)
{
}

const QString TheAwkwardYeti::_id                 = QString("theawkwardyeti");
const QString TheAwkwardYeti::_name               = QString("The Awkward Yeti");
const QColor TheAwkwardYeti::_color               = QColor(255, 200, 47);
const QStringList TheAwkwardYeti::_authors        = QStringList("Nick Seluk");
const QUrl TheAwkwardYeti::_homepage              = QUrl("http://theawkwardyeti.com/");
const QLocale::Country TheAwkwardYeti::_country   = QLocale::UnitedStates;
const QLocale::Language TheAwkwardYeti::_language = QLocale::English;
const QDate TheAwkwardYeti::_startDate            = QDate::fromString("2012-09-12", Qt::ISODate);
const QDate TheAwkwardYeti::_endDate              = QDate::currentDate();
const QUrl TheAwkwardYeti::_stripSourceUrl        = QUrl("http://theawkwardyeti.com/");

QUrl TheAwkwardYeti::extractStripImageUrl(QByteArray data)
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
