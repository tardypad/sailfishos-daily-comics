/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LeChat.h"

#include <QDebug>

LeChat::LeChat(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("lechat");
    m_info.name           = QString("Le Chat");
    m_info.color          = QColor(38, 203, 171);
    m_info.authors        = QStringList("Philippe Geluck");
    m_info.homepage       = QUrl("http://geluck.com/");
    m_info.country        = QLocale::Belgium;
    m_info.language       = QLocale::French;
    m_info.stripSourceUrl = QUrl("http://geluck.com/dessin.html");
}

QUrl LeChat::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/strip/[^\"]*)\"");
}
