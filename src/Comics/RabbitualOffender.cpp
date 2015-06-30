/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "RabbitualOffender.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

RabbitualOffender::RabbitualOffender(QObject *parent) :
    Comic(parent)
{
}

const QString RabbitualOffender::_id                 = QString("rabbitualoffender");
const QString RabbitualOffender::_name               = QString("Rabbitual Offender");
const QColor RabbitualOffender::_color               = QColor(193, 204, 232);
const QStringList RabbitualOffender::_authors        = QStringList() << "Edward Gee" << "Wade Crodhil";
const QUrl RabbitualOffender::_homepage              = QUrl("http://rabbitualoffender.tumblr.com/");
const QLocale::Country RabbitualOffender::_country   = QLocale::UnitedStates;
const QLocale::Language RabbitualOffender::_language = QLocale::English;
const QDate RabbitualOffender::_startDate            = QDate::fromString("2014-11-08", Qt::ISODate);
const QDate RabbitualOffender::_endDate              = QDate::currentDate();
const QUrl RabbitualOffender::_stripSourceUrl        = QUrl("http://rabbitualoffender.tumblr.com/");

QUrl RabbitualOffender::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"");
    QRegularExpressionMatchIterator matchIterator = reg.globalMatch(html);

    if (!matchIterator.hasNext())
        return QUrl();

    matchIterator.next();

    if (!matchIterator.hasNext())
        return QUrl();

    QRegularExpressionMatch match = matchIterator.next();

    QString src = match.captured(1);

    return QUrl(src);
}
