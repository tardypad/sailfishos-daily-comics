/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DarthsAndDroids.h"

#include <QDebug>

DarthsAndDroids::DarthsAndDroids(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl DarthsAndDroids::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "src=&quot;([^&]*/comics/[^&]*)&quot;");
}
