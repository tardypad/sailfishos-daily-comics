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
    m_info.id             = QString("rabbitualoffender");
    m_info.name           = QString("Rabbitual Offender");
    m_info.color          = QColor(193, 204, 232);
    m_info.authors        = QStringList() << "Edward Gee" << "Wade Crodhil";
    m_info.homepage       = QUrl("http://rabbitualoffender.tumblr.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2014-11-08", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://rabbitualoffender.tumblr.com/");
}

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
