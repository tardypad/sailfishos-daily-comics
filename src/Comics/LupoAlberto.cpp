/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LupoAlberto.h"

#include <QDebug>

LupoAlberto::LupoAlberto(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("lupoalberto");
    m_info.name           = QString("Lupo Alberto");
    m_info.color          = QColor(151, 205, 241);
    m_info.authors        = QStringList("Guido Silvestri");
    m_info.homepage       = QUrl("http://lupoalberto.it/");
    m_info.language       = QLocale::Italian;
    m_info.stripSourceUrl = QUrl("http://lupoalberto.agenzia2d.it/");
}

QUrl LupoAlberto::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "href=\"([^\"]*/tavola-settimana/[^\"]*)\"");
}
