/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "KamalaLuonto.h"

#include <QDebug>

KamalaLuonto::KamalaLuonto(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("kamalaluonto");
}

QUrl KamalaLuonto::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "data-original=\"([^\"]*)\"");
}
