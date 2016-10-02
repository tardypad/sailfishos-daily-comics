/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "NedroidPictureDiary.h"

#include <QDebug>

NedroidPictureDiary::NedroidPictureDiary(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl NedroidPictureDiary::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/comic/[^\"]*)\"");
}
