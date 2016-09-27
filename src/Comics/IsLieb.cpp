/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "IsLieb.h"

#include <QDebug>

IsLieb::IsLieb(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("islieb");
    m_info.name           = QString("Is lieb?");
    m_info.color          = QColor(226, 72, 64);
    m_info.authors        = QStringList("Ey Lou Flynn");
    m_info.homepage       = QUrl("http://islieb.de/");
    m_info.language       = QLocale::German;
    m_info.stripSourceUrl = QUrl("http://islieb.de/feed/");
}

QUrl IsLieb::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
