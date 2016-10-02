/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TubeyToons.h"

#include <QDebug>

TubeyToons::TubeyToons(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl TubeyToons::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"", 2);
}
