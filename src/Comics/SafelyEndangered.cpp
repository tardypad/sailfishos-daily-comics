/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "SafelyEndangered.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

SafelyEndangered::SafelyEndangered(QObject *parent) :
    Comic(parent)
{
}

const QString SafelyEndangered::_id                 = QString("safelyendangered");
const QString SafelyEndangered::_name               = QString("Safely Endangered");
const QColor SafelyEndangered::_color               = QColor(71, 91, 130);
const QStringList SafelyEndangered::_authors        = QStringList("Chris McCoy");
const QUrl SafelyEndangered::_homepage              = QUrl("http://www.safelyendangered.com/");
const QLocale::Country SafelyEndangered::_country   = QLocale::UnitedKingdom;
const QLocale::Language SafelyEndangered::_language = QLocale::English;
const QDate SafelyEndangered::_startDate            = QDate::fromString("2012-11-11", Qt::ISODate);
const QDate SafelyEndangered::_endDate              = QDate::currentDate();
const QUrl SafelyEndangered::_stripSourceUrl        = QUrl("http://www.safelyendangered.com/");

QUrl SafelyEndangered::extractStripImageUrl(QByteArray data)
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
