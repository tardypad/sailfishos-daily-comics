/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ShitHappens.h"

#include <QDebug>

ShitHappens::ShitHappens(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("shithappens");
    m_info.name           = QString("Shit happens!");
    m_info.color          = QColor(147, 209, 246);
    m_info.authors        = QStringList("Ralph Ruthe");
    m_info.homepage       = QUrl("http://ruthe.de/");
    m_info.country        = QLocale::Germany;
    m_info.language       = QLocale::German;
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://ruthe.de/cartoon/");
}

QUrl ShitHappens::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/cartoons/[^\"]*)\"");
}
