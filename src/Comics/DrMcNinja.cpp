/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DrMcNinja.h"

#include <QDebug>

DrMcNinja::DrMcNinja(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("drmcninja");
    m_info.name           = QString("The Adventures of Dr. McNinja");
    m_info.color          = QColor(125, 125, 125);
    m_info.authors        = QStringList("Christopher Hastings");
    m_info.homepage       = QUrl("http://drmcninja.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://drmcninja.com/");
}

QUrl DrMcNinja::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/comics/[^\"]*)\"");
}
