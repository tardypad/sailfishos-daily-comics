/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Swamp.h"

#include <QDebug>

Swamp::Swamp(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("swamp");
    m_info.name           = QString("Swamp");
    m_info.color          = QColor(241, 90, 69);
    m_info.authors        = QStringList("Gary Clark");
    m_info.homepage       = QUrl("https://www.swamp.com.au/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.swamp.com.au/cartoons.php");
}

QUrl Swamp::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src='(strips/[^']*)'");
}
