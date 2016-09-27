/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "SarahsScribbles.h"

#include <QDebug>

SarahsScribbles::SarahsScribbles(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("sarahsscribbles");
    m_info.name           = QString("Sarah's Scribbles");
    m_info.color          = QColor(3, 193, 217);
    m_info.authors        = QStringList("Sarah Andersen");
    m_info.homepage       = QUrl("http://sarahcandersen.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://sarahcandersen.com/rss");
}

QUrl SarahsScribbles::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "&lt;img[^&]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"");
}
