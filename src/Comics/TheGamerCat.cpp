/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheGamerCat.h"

#include <QDebug>

TheGamerCat::TheGamerCat(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("thegamercat");
    m_info.name           = QString("The GaMERCaT");
    m_info.color          = QColor(179, 179, 179);
    m_info.authors        = QStringList("Samantha Whitten");
    m_info.homepage       = QUrl("http://www.thegamercat.com");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.thegamercat.com/");
}

QUrl TheGamerCat::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
