/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ViiviJaWagner.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

ViiviJaWagner::ViiviJaWagner(QObject *parent) :
    Comic(parent)
{
}

const QString ViiviJaWagner::_id                 = QString("viivijawagner");
const QString ViiviJaWagner::_name               = QString("Viivi ja Wagner");
const QColor ViiviJaWagner::_color               = QColor(222, 42, 131);
const QStringList ViiviJaWagner::_authors        = QStringList("Jussi \"Juba\" Tuomola");
const QUrl ViiviJaWagner::_homepage              = QUrl("http://www.viivijawagner.net/");
const QLocale::Country ViiviJaWagner::_country   = QLocale::Finland;
const QLocale::Language ViiviJaWagner::_language = QLocale::Finnish;
const QDate ViiviJaWagner::_startDate            = QDate::fromString("1997-10-06", Qt::ISODate);
const QDate ViiviJaWagner::_endDate              = QDate::currentDate();
const QUrl ViiviJaWagner::_stripSourceUrl        = QUrl("http://www.hs.fi/m/viivijawagner/");

QUrl ViiviJaWagner::extractStripImageUrl(QByteArray data)
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
