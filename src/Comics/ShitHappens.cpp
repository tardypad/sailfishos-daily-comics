/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ShitHappens.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

ShitHappens::ShitHappens(QObject *parent) :
    Comic(parent)
{
}

const QString ShitHappens::_id                 = QString("shithappens");
const QString ShitHappens::_name               = QString("Shit happens!");
const QColor ShitHappens::_color               = QColor(147, 209, 246);
const QStringList ShitHappens::_authors        = QStringList("Ralph Ruthe");
const QUrl ShitHappens::_homepage              = QUrl("http://ruthe.de/");
const QLocale::Country ShitHappens::_country   = QLocale::Germany;
const QLocale::Language ShitHappens::_language = QLocale::German;
const QDate ShitHappens::_startDate            = QDate();
const QDate ShitHappens::_endDate              = QDate::currentDate();
const QUrl ShitHappens::_stripSourceUrl        = QUrl("http://ruthe.de/cartoon/");

QUrl ShitHappens::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/cartoons/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://ruthe.de/" + src);
}
