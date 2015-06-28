/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "SadSacks.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

SadSacks::SadSacks(QObject *parent) :
    Comic(parent)
{
}

const QString SadSacks::_id                 = QString("sadsacks");
const QString SadSacks::_name               = QString("Sad Sacks");
const QColor SadSacks::_color               = QColor(188, 160, 139);
const QStringList SadSacks::_authors        = QStringList() << "James \"Wiz\" Wallace" << "Johnny \"Wasabi\" Larocque";
const QUrl SadSacks::_homepage              = QUrl("http://www.sadsacks.ca/");
const QLocale::Country SadSacks::_country   = QLocale::Canada;
const QLocale::Language SadSacks::_language = QLocale::English;
const QDate SadSacks::_startDate            = QDate::fromString("2015-01-05", Qt::ISODate);
const QDate SadSacks::_endDate              = QDate::currentDate();
const QUrl SadSacks::_stripSourceUrl        = QUrl("http://www.sadsacks.ca/");

QUrl SadSacks::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(images/comic/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://www.sadsacks.ca/" + src);
}
