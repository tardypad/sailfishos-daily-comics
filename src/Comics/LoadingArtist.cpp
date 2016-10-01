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
    m_info.id = QString("loadingartist");
}

QUrl LoadingArtist::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
