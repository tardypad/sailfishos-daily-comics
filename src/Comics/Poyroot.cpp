/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Poyroot.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Poyroot::Poyroot(QObject *parent) :
    Comic(parent)
{
}

const QString Poyroot::_id                 = QString("poyroot");
const QString Poyroot::_name               = QString("Pöyrööt");
const QColor Poyroot::_color               = QColor(160, 207, 79);
const QStringList Poyroot::_authors        = QStringList() << "Arttu Seppälä" << "Liisa Seppälä" << "Tiia Pelkola";
const QUrl Poyroot::_homepage              = QUrl("http://www.poyroot.fi");
const QLocale::Country Poyroot::_country   = QLocale::Finland;
const QLocale::Language Poyroot::_language = QLocale::Finnish;
const QDate Poyroot::_startDate            = QDate();
const QDate Poyroot::_endDate              = QDate::currentDate();
const QUrl Poyroot::_stripSourceUrl        = QUrl("http://www.poyroot.fi/sarjakuvat/");

QUrl Poyroot::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/poyroot_[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
