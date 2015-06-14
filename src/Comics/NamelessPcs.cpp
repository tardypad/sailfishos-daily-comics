/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "NamelessPcs.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

NamelessPcs::NamelessPcs(QObject *parent) :
    Comic(parent)
{
}

const QString NamelessPcs::_id                 = QString("namelesspcs");
const QString NamelessPcs::_name               = QString("Nameless PCs");
const QColor NamelessPcs::_color               = QColor(116, 209, 240);
const QStringList NamelessPcs::_authors        = QStringList("Wesley Hall");
const QUrl NamelessPcs::_homepage              = QUrl("http://namelesspcs.com/");
const QLocale::Country NamelessPcs::_country   = QLocale::UnitedStates;
const QLocale::Language NamelessPcs::_language = QLocale::English;
const QDate NamelessPcs::_startDate            = QDate::fromString("2010-09-26", Qt::ISODate);
const QDate NamelessPcs::_endDate              = QDate::currentDate();
const QUrl NamelessPcs::_stripSourceUrl        = QUrl("http://namelesspcs.com/");

QUrl NamelessPcs::extractStripUrl(QByteArray data)
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
