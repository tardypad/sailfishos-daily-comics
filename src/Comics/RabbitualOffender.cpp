/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "RabbitualOffender.h"

#include <QDebug>

RabbitualOffender::RabbitualOffender(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("rabbitualoffender");
    m_info.name           = QString("Rabbitual Offender");
    m_info.color          = QColor(193, 189, 224);
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
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"", 2);
}
