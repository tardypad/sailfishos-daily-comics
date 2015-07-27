/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DinosaurComics.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

DinosaurComics::DinosaurComics(QObject *parent) :
    Comic(parent)
{
}

const QString DinosaurComics::_id                 = QString("dinosaurcomics");
const QString DinosaurComics::_name               = QString("Dinosaur Comics");
const QColor DinosaurComics::_color               = QColor(120, 106, 255);
const QStringList DinosaurComics::_authors        = QStringList("Ryan North");
const QUrl DinosaurComics::_homepage              = QUrl("http://www.qwantz.com/");
const QLocale::Country DinosaurComics::_country   = QLocale::Canada;
const QLocale::Language DinosaurComics::_language = QLocale::English;
const QDate DinosaurComics::_startDate            = QDate::fromString("2003-02-01", Qt::ISODate);
const QDate DinosaurComics::_endDate              = QDate::currentDate();
const QUrl DinosaurComics::_stripSourceUrl        = QUrl("http://www.qwantz.com/index.php");

QUrl DinosaurComics::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*/comics/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
