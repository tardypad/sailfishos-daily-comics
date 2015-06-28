/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DennisTheMenace.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

DennisTheMenace::DennisTheMenace(QObject *parent) :
    Comic(parent)
{
}

const QString DennisTheMenace::_id                 = QString("dennisthemenace");
const QString DennisTheMenace::_name               = QString("Dennis The Menace");
const QColor DennisTheMenace::_color               = QColor(246, 255, 84);
const QStringList DennisTheMenace::_authors        = QStringList() << "Hank Ketcham" << "Marcus Hamilton" << "Ron Ferdinand";
const QUrl DennisTheMenace::_homepage              = QUrl("http://dennisthemenace.com/");
const QLocale::Country DennisTheMenace::_country   = QLocale::UnitedStates;
const QLocale::Language DennisTheMenace::_language = QLocale::English;
const QDate DennisTheMenace::_startDate            = QDate::fromString("1951-03-12", Qt::ISODate);
const QDate DennisTheMenace::_endDate              = QDate::currentDate();
const QUrl DennisTheMenace::_stripSourceUrl        = QUrl("http://dennisthemenace.com/");

QUrl DennisTheMenace::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<meta property=\"og:image\" content=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
