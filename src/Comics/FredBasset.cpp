/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FredBasset.h"

#include <QDebug>

FredBasset::FredBasset(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("fredbasset");
    m_info.name           = QString("Fred Basset");
    m_info.color          = QColor(203, 176, 61);
    m_info.authors        = QStringList() << "Alex Graham" << "Michael Martin";
    m_info.homepage       = QUrl("http://www.gocomics.com/fredbasset/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/fredbasset/");
}

QUrl FredBasset::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
