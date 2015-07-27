/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "CheerUpEmoKid.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

CheerUpEmoKid::CheerUpEmoKid(QObject *parent) :
    Comic(parent)
{
}

const QString CheerUpEmoKid::_id                 = QString("cheerupemokid");
const QString CheerUpEmoKid::_name               = QString("Cheer Up, Emo Kid");
const QColor CheerUpEmoKid::_color               = QColor(51, 51, 51);
const QStringList CheerUpEmoKid::_authors        = QStringList("Enzo");
const QUrl CheerUpEmoKid::_homepage              = QUrl("http://www.cheerupemokid.com/");
const QLocale::Country CheerUpEmoKid::_country   = QLocale::Canada;
const QLocale::Language CheerUpEmoKid::_language = QLocale::English;
const QDate CheerUpEmoKid::_startDate            = QDate::fromString("2008-10-10", Qt::ISODate);
const QDate CheerUpEmoKid::_endDate              = QDate::currentDate();
const QUrl CheerUpEmoKid::_stripSourceUrl        = QUrl("http://www.cheerupemokid.com/");

QUrl CheerUpEmoKid::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
