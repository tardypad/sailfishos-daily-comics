/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "CyanideAndHappiness.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

CyanideAndHappiness::CyanideAndHappiness(QObject *parent) :
    Comic(parent)
{
}

const QString CyanideAndHappiness::_id                 = QString("cyanideandhappiness");
const QString CyanideAndHappiness::_name               = QString("Cyanide & Happiness");
const QColor CyanideAndHappiness::_color               = QColor(93, 76, 154);
const QStringList CyanideAndHappiness::_authors        = QStringList() << "Matt Melvin" << "Rob DenBleyker"
                                                                       << "Kris Wilson" << "Dave McElfatrick";
const QUrl CyanideAndHappiness::_homepage              = QUrl("http://explosm.net/");
const QLocale::Country CyanideAndHappiness::_country   = QLocale::UnitedStates;
const QLocale::Language CyanideAndHappiness::_language = QLocale::English;
const QDate CyanideAndHappiness::_startDate            = QDate::fromString("2004-12-09", Qt::ISODate);
const QDate CyanideAndHappiness::_endDate              = QDate::currentDate();
const QUrl CyanideAndHappiness::_stripSourceUrl        = QUrl("http://explosm.net/");

QUrl CyanideAndHappiness::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/comics/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http:" + src);
}
