/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PirateMike.h"

#include <QDebug>

PirateMike::PirateMike(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl PirateMike::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<media:content url=\"([^\"]*piratemikecomics.files.wordpress.com/[^\"]*)\"");
}
