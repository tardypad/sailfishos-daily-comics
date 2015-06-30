/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LupoAlberto.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

LupoAlberto::LupoAlberto(QObject *parent) :
    Comic(parent)
{
}

const QString LupoAlberto::_id                 = QString("lupoalberto");
const QString LupoAlberto::_name               = QString("Lupo Alberto");
const QColor LupoAlberto::_color               = QColor(119, 188, 243);
const QStringList LupoAlberto::_authors        = QStringList("Guido Silvestri");
const QUrl LupoAlberto::_homepage              = QUrl("http://lupoalberto.it/");
const QLocale::Country LupoAlberto::_country   = QLocale::Italy;
const QLocale::Language LupoAlberto::_language = QLocale::Italian;
const QDate LupoAlberto::_startDate            = QDate::fromString("1974-02", "yyyy-MM");
const QDate LupoAlberto::_endDate              = QDate::currentDate();
const QUrl LupoAlberto::_stripSourceUrl        = QUrl("http://lupoalberto.agenzia2d.it/");

QUrl LupoAlberto::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("href=\"([^\"]*/tavola-settimana/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://lupoalberto.agenzia2d.it/" + src);
}
