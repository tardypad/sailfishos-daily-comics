/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ExtraOrdinary.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

ExtraOrdinary::ExtraOrdinary(QObject *parent) :
    Comic(parent)
{
}

const QString ExtraOrdinary::_id                 = QString("extraordinary");
const QString ExtraOrdinary::_name               = QString("Extra Ordinary");
const QColor ExtraOrdinary::_color               = QColor(175, 175, 175);
const QStringList ExtraOrdinary::_authors        = QStringList("Li Chen");
const QUrl ExtraOrdinary::_homepage              = QUrl("http://www.exocomics.com/");
const QLocale::Country ExtraOrdinary::_country   = QLocale::NewZealand;
const QLocale::Language ExtraOrdinary::_language = QLocale::English;
const QDate ExtraOrdinary::_startDate            = QDate::fromString("2009", "yyyy");
const QDate ExtraOrdinary::_endDate              = QDate::currentDate();
const QUrl ExtraOrdinary::_stripSourceUrl        = QUrl("http://www.exocomics.com/");

QUrl ExtraOrdinary::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/comics/comics/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
