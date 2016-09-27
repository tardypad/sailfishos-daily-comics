/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Peanuts.h"

#include <QDebug>

Peanuts::Peanuts(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("peanuts");
    m_info.name           = QString("Peanuts");
    m_info.color          = QColor(255, 223, 30);
    m_info.authors        = QStringList("Charles Monroe Schulz");
    m_info.homepage       = QUrl("http://www.peanuts.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/peanuts/");
}

QUrl Peanuts::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
