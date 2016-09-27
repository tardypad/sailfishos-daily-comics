/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DarthsAndDroids.h"

#include <QDebug>

DarthsAndDroids::DarthsAndDroids(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("darthsanddroids");
    m_info.name           = QString("Darths and Droids");
    m_info.color          = QColor(243, 254, 100);
    m_info.authors        = QStringList() << "Andrew Coker" << "Andrew Shellshear" << "David Karlov"
                                          << "David McLeish" << "David Morgan-Mar" << "Ian Boreham"
                                          << "Loki Patrick" << "Steven Irrgang";
    m_info.homepage       = QUrl("http://www.darthsanddroids.net/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.darthsanddroids.net/rss_noannotation.xml");
}

QUrl DarthsAndDroids::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "src=&quot;([^&]*/comics/[^&]*)&quot;");
}
