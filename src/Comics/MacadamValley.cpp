/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "MacadamValley.h"

#include <QDebug>

MacadamValley::MacadamValley(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("macadamvalley");
    m_info.name           = QString("Macadam Valley");
    m_info.color          = QColor(185, 167, 131);
    m_info.authors        = QStringList("Ben Dessy");
    m_info.homepage       = QUrl("http://macadamvalley.com/");
    m_info.country        = QLocale::France;
    m_info.language       = QLocale::French;
    m_info.stripSourceUrl = QUrl("http://macadamvalley.com/feed/");
}

QUrl MacadamValley::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
