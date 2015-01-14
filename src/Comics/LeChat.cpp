/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LeChat.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

LeChat::LeChat(QObject *parent) :
    Comic(parent)
{
}

const QString LeChat::_id                 = QString("lechat");
const QString LeChat::_name               = QString("Le Chat");
const QColor LeChat::_color               = QColor(38, 203, 171);
const QString LeChat::_author             = QString("Philippe Geluck");
const QUrl LeChat::_homepage              = QUrl("http://geluck.com/");
const QLocale::Country LeChat::_country   = QLocale::Belgium;
const QLocale::Language LeChat::_language = QLocale::French;
const QDate LeChat::_startDate            = QDate::fromString("1983-03-22", Qt::ISODate);
const QDate LeChat::_endDate              = QDate::currentDate();
const QUrl LeChat::_stripSourceUrl        = QUrl("http://geluck.com/dessin.html");

QUrl LeChat::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/strip/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://geluck.com/" + src);
}
