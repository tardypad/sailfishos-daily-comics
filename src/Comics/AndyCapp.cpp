/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "AndyCapp.h"

#include <QDebug>

AndyCapp::AndyCapp(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("andycapp");
    m_info.name           = QString("Andy Capp");
    m_info.color          = QColor(253, 244, 113);
    m_info.authors        = QStringList("Reg Smythe");
    m_info.homepage       = QUrl("http://www.gocomics.com/andycapp");
    m_info.country        = QLocale::UnitedKingdom;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1957-08-05", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/andycapp");
}

QUrl AndyCapp::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
