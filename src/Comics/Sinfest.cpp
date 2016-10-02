/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Sinfest.h"

#include <QDebug>

Sinfest::Sinfest(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl Sinfest::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/comics/[^\"]*)\"");
}
