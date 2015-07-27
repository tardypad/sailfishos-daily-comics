/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LoadingArtist.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

LoadingArtist::LoadingArtist(QObject *parent) :
    Comic(parent)
{
}

const QString LoadingArtist::_id                 = QString("loadingartist");
const QString LoadingArtist::_name               = QString("Loading Artist");
const QColor LoadingArtist::_color               = QColor(253, 104, 1);
const QStringList LoadingArtist::_authors        = QStringList("Gregor Czaykowski");
const QUrl LoadingArtist::_homepage              = QUrl("http://www.loadingartist.com/");
const QLocale::Country LoadingArtist::_country   = QLocale::NewZealand;
const QLocale::Language LoadingArtist::_language = QLocale::English;
const QDate LoadingArtist::_startDate            = QDate::fromString("2011-01-04", Qt::ISODate);
const QDate LoadingArtist::_endDate              = QDate::currentDate();
const QUrl LoadingArtist::_stripSourceUrl        = QUrl("http://www.loadingartist.com/latest");

QUrl LoadingArtist::extractStripImageUrl(QByteArray data)
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
