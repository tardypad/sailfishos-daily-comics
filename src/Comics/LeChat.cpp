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
    m_info.id = QString("lechat");
}

QUrl LeChat::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/strip/[^\"]*)\"");
}
