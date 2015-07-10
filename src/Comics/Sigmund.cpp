/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Sigmund.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Sigmund::Sigmund(QObject *parent) :
    Comic(parent)
{
}

const QString Sigmund::_id                 = QString("sigmund");
const QString Sigmund::_name               = QString("Sigmund");
const QColor Sigmund::_color               = QColor(255, 255, 169);
const QStringList Sigmund::_authors        = QStringList("Peter de Wit");
const QUrl Sigmund::_homepage              = QUrl("http://www.sigmund.nl/");
const QLocale::Country Sigmund::_country   = QLocale::Netherlands;
const QLocale::Language Sigmund::_language = QLocale::Dutch;
const QDate Sigmund::_startDate            = QDate::fromString("1992", "yyyy");
const QDate Sigmund::_endDate              = QDate::currentDate();
const QUrl Sigmund::_stripSourceUrl        = QUrl("http://www.sigmund.nl/?p=home");

QUrl Sigmund::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=(strips/[^ ]*) ");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://www.sigmund.nl/" + src);
}
