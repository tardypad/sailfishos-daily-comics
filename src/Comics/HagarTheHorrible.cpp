/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "HagarTheHorrible.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

HagarTheHorrible::HagarTheHorrible(QObject *parent) :
    Comic(parent)
{
}

const QString HagarTheHorrible::_id                 = QString("hagarthehorrible");
const QString HagarTheHorrible::_name               = QString("Hägar the Horrible");
const QColor HagarTheHorrible::_color               = QColor(216, 164, 55);
const QStringList HagarTheHorrible::_authors        = QStringList() << "Dik Browne" << "Chris Browne";
const QUrl HagarTheHorrible::_homepage              = QUrl("http://hagarthehorrible.com/");
const QLocale::Country HagarTheHorrible::_country   = QLocale::UnitedStates;
const QLocale::Language HagarTheHorrible::_language = QLocale::English;
const QDate HagarTheHorrible::_startDate            = QDate::fromString("1973-02-04", Qt::ISODate);
const QDate HagarTheHorrible::_endDate              = QDate::currentDate();
const QUrl HagarTheHorrible::_stripSourceUrl        = QUrl("http://hagarthehorrible.com/");

QUrl HagarTheHorrible::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*content\\.php[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
