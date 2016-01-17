/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TubeyToons.h"

#include <QDebug>

TubeyToons::TubeyToons(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("tubeytoons");
    m_info.name           = QString("Tubey Toons");
    m_info.color          = QColor(109, 79, 117);
    m_info.authors        = QStringList() << "Tubey" << "Wamn";
    m_info.homepage       = QUrl("http://tubeytoons.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2013-01-01", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://tubeytoons.com/");
}

QUrl TubeyToons::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\'(.*/images/comics/[^\']*)\'");
}
