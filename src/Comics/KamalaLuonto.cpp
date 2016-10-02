/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "KamalaLuonto.h"

#include <QDebug>

KamalaLuonto::KamalaLuonto(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl KamalaLuonto::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "data-original=\"([^\"]*)\"");
}
