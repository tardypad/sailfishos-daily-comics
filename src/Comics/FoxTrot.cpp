/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FoxTrot.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

FoxTrot::FoxTrot(QObject *parent) :
    Comic(parent)
{
}

const QString FoxTrot::_id                 = QString("foxtrot");
const QString FoxTrot::_name               = QString("FoxTrot");
const QColor FoxTrot::_color               = QColor(222, 196, 169);
const QStringList FoxTrot::_authors        = QStringList("Bill Amend");
const QUrl FoxTrot::_homepage              = QUrl("http://www.foxtrot.com");
const QLocale::Country FoxTrot::_country   = QLocale::UnitedStates;
const QLocale::Language FoxTrot::_language = QLocale::English;
const QDate FoxTrot::_startDate            = QDate::fromString("1988-04-10", Qt::ISODate);
const QDate FoxTrot::_endDate              = QDate::currentDate();
const QUrl FoxTrot::_stripSourceUrl        = QUrl("http://www.gocomics.com/foxtrot");

QUrl FoxTrot::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
