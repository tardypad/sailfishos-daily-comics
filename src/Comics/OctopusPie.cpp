/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "OctopusPie.h"

#include <QDebug>

OctopusPie::OctopusPie(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("octopuspie");
    m_info.name           = QString("Octopus Pie");
    m_info.color          = QColor(104, 183, 190);
    m_info.authors        = QStringList("Meredith Gran");
    m_info.homepage       = QUrl("http://octopuspie.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2007-05-14", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://octopuspie.com/");
}

QUrl OctopusPie::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/strippy/[^\"]*)\"");
}
