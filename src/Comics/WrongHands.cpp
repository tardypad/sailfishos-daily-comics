/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "WrongHands.h"

#include <QDebug>

WrongHands::WrongHands(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("wronghands");
}

QUrl WrongHands::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*wronghands1.files.wordpress.com/[^\"]*)\"");
}
