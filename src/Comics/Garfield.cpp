/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Garfield.h"

#include <QDebug>

Garfield::Garfield(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("garfield");
    m_info.name           = QString("Garfield");
    m_info.color          = QColor(242, 186, 31);
    m_info.authors        = QStringList("Jim Davis");
    m_info.homepage       = QUrl("http://garfield.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1978-06-19", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://garfield.com/");
}

QUrl Garfield::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/comics/[^\"]*)\"");
}
