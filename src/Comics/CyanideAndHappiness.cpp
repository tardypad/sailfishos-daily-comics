/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "CyanideAndHappiness.h"

#include <QDebug>

CyanideAndHappiness::CyanideAndHappiness(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("cyanideandhappiness");
    m_info.name           = QString("Cyanide & Happiness");
    m_info.color          = QColor(46, 38, 77);
    m_info.authors        = QStringList() << "Matt Melvin" << "Rob DenBleyker"
                                          << "Kris Wilson" << "Dave McElfatrick";
    m_info.homepage       = QUrl("http://explosm.net/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://explosm.net/");
}

QUrl CyanideAndHappiness::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/comics/[^\"]*)\"");
}
