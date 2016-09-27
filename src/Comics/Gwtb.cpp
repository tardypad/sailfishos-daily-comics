/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Gwtb.h"

#include <QDebug>

Gwtb::Gwtb(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("gwtb");
    m_info.name           = QString("Gone With The Blastwave");
    m_info.color          = QColor(221, 171, 76);
    m_info.authors        = QStringList("Kimmo Lemetti");
    m_info.homepage       = QUrl("http://www.blastwave-comic.com");
    m_info.country        = QLocale::Finland;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.blastwave-comic.com/");
}

QUrl Gwtb::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(./comics/[^\"]*)\"");
}
