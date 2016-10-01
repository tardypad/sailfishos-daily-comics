/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheHatAndFat.h"

#include <QDebug>

TheHatAndFat::TheHatAndFat(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("thehatandfat");
}

QUrl TheHatAndFat::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(https://thehatandfat.files.wordpress.com/[^\"]*)\"");
}
