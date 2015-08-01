/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FokkeEnSukke.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

FokkeEnSukke::FokkeEnSukke(QObject *parent) :
    Comic(parent)
{
}

const QString FokkeEnSukke::_id                 = QString("fokkeensukke");
const QString FokkeEnSukke::_name               = QString("Fokke en Sukke");
const QColor FokkeEnSukke::_color               = QColor(214, 26, 33);
const QStringList FokkeEnSukke::_authors        = QStringList() << "Jean-Marc van Tol" << "John Reid" << "Bastiaan Geleijnse";
const QUrl FokkeEnSukke::_homepage              = QUrl("http://foksuk.nl/");
const QLocale::Country FokkeEnSukke::_country   = QLocale::Netherlands;
const QLocale::Language FokkeEnSukke::_language = QLocale::Dutch;
const QDate FokkeEnSukke::_startDate            = QDate::fromString("1994", "yyyy");
const QDate FokkeEnSukke::_endDate              = QDate::currentDate();
const QUrl FokkeEnSukke::_stripSourceUrl        = QUrl("http://foksuk.nl/");

QUrl FokkeEnSukke::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(content/formfield_files/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://foksuk.nl/" + src);
}
