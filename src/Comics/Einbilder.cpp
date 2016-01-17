/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Einbilder.h"

#include <QDebug>

Einbilder::Einbilder(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("einbilder");
    m_info.name           = QString("Einbilder");
    m_info.color          = QColor(79, 95, 110);
    m_info.authors        = QStringList("Daniel Noll");
    m_info.homepage       = QUrl("http://www.einbilder.de/");
    m_info.country        = QLocale::Germany;
    m_info.language       = QLocale::German;
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.einbilder.de/");
}

QUrl Einbilder::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(images/cartoons/[^\"]*)\"");
}
