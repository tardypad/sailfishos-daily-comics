/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Buni.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Buni::Buni(QObject *parent) :
    Comic(parent)
{
}

const QString Buni::_id                 = QString("buni");
const QString Buni::_name               = QString("Buni");
const QColor Buni::_color               = QColor(87, 110, 152);
const QStringList Buni::_authors        = QStringList("Ryan Pagelow");
const QUrl Buni::_homepage              = QUrl("http://www.bunicomic.com/");
const QLocale::Country Buni::_country   = QLocale::UnitedStates;
const QLocale::Language Buni::_language = QLocale::English;
const QDate Buni::_startDate            = QDate::fromString("2010-01-01", Qt::ISODate);
const QDate Buni::_endDate              = QDate::currentDate();
const QUrl Buni::_stripSourceUrl        = QUrl("http://www.bunicomic.com/");

QUrl Buni::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<div id=\"comic\">\n<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
