/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LizClimo.h"

#include <QDebug>

LizClimo::LizClimo(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl LizClimo::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "&lt;img[^&]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"");
}
