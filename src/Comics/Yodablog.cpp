/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Yodablog.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Yodablog::Yodablog(QObject *parent) :
    Comic(parent)
{
}

const QString Yodablog::_id                 = QString("yodablog");
const QString Yodablog::_name               = QString("Yodablog");
const QColor Yodablog::_color               = QColor(154, 183, 93);
const QStringList Yodablog::_authors        = QStringList("Thierry Vivien");
const QUrl Yodablog::_homepage              = QUrl("http://www.yodablog.net/");
const QLocale::Country Yodablog::_country   = QLocale::France;
const QLocale::Language Yodablog::_language = QLocale::French;
const QDate Yodablog::_startDate            = QDate::fromString("2009-01-01", Qt::ISODate);
const QDate Yodablog::_endDate              = QDate::currentDate();
const QUrl Yodablog::_stripSourceUrl        = QUrl("http://www.yodablog.net/?feed=rss2");

QUrl Yodablog::extractStripImageUrl(QByteArray data)
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
