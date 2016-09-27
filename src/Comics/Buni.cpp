/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Buni.h"

#include <QDebug>

Buni::Buni(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("buni");
    m_info.name           = QString("Buni");
    m_info.color          = QColor(87, 110, 152);
    m_info.authors        = QStringList("Ryan Pagelow");
    m_info.homepage       = QUrl("http://www.bunicomic.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.bunicomic.com/");
}

QUrl Buni::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<div id=\"comic\">\n<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
