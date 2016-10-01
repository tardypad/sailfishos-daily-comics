/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DarthsAndDroids.h"

#include <QDebug>

DarthsAndDroids::DarthsAndDroids(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("darthsanddroids");
}

QUrl DarthsAndDroids::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "src=&quot;([^&]*/comics/[^&]*)&quot;");
}
