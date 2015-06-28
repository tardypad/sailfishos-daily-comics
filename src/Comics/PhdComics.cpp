/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PhdComics.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

PhdComics::PhdComics(QObject *parent) :
    Comic(parent)
{
}

const QString PhdComics::_id                 = QString("phdcomics");
const QString PhdComics::_name               = QString("Piled Higher and Deeper");
const QColor PhdComics::_color               = QColor(82, 105, 125);
const QStringList PhdComics::_authors        = QStringList("Jorge Cham");
const QUrl PhdComics::_homepage              = QUrl("http://phdcomics.com/");
const QLocale::Country PhdComics::_country   = QLocale::Panama;
const QLocale::Language PhdComics::_language = QLocale::English;
const QDate PhdComics::_startDate            = QDate::fromString("1997-10-27", Qt::ISODate);
const QDate PhdComics::_endDate              = QDate::currentDate();
const QUrl PhdComics::_stripSourceUrl        = QUrl("http://phdcomics.com/comics.php");

QUrl PhdComics::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img id=comic[^>]*src=([^ ]*)");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
