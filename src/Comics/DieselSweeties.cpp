/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DieselSweeties.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

DieselSweeties::DieselSweeties(QObject *parent) :
    Comic(parent)
{
}

const QString DieselSweeties::_id                 = QString("dieselsweeties");
const QString DieselSweeties::_name               = QString("Diesel Sweeties");
const QColor DieselSweeties::_color               = QColor(116, 141, 66);
const QStringList DieselSweeties::_authors        = QStringList("Richard Stevens III");
const QUrl DieselSweeties::_homepage              = QUrl("http://dieselsweeties.com/");
const QLocale::Country DieselSweeties::_country   = QLocale::UnitedStates;
const QLocale::Language DieselSweeties::_language = QLocale::English;
const QDate DieselSweeties::_startDate            = QDate::fromString("2000-04", "yyyy-MM");
const QDate DieselSweeties::_endDate              = QDate::currentDate();
const QUrl DieselSweeties::_stripSourceUrl        = QUrl("http://dieselsweeties.com/");

QUrl DieselSweeties::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/hstrips/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://www.dieselsweeties.com/" + src);
}
