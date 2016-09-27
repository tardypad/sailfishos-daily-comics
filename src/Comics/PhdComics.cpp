/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PhdComics.h"

#include <QDebug>

PhdComics::PhdComics(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("phdcomics");
    m_info.name           = QString("Piled Higher and Deeper");
    m_info.color          = QColor(82, 104, 125);
    m_info.authors        = QStringList("Jorge Cham");
    m_info.homepage       = QUrl("http://phdcomics.com/");
    m_info.country        = QLocale::Panama;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://phdcomics.com/comics.php");
}

QUrl PhdComics::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img id=comic[^>]*src=([^ ]*)");
}
