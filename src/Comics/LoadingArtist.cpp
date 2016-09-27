/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LoadingArtist.h"

#include <QDebug>

LoadingArtist::LoadingArtist(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("loadingartist");
    m_info.name           = QString("Loading Artist");
    m_info.color          = QColor(253, 104, 1);
    m_info.authors        = QStringList("Gregor Czaykowski");
    m_info.homepage       = QUrl("http://www.loadingartist.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.loadingartist.com/latest");
}

QUrl LoadingArtist::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
