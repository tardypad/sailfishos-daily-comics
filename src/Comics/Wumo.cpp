/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Wumo.h"

#include <QDebug>

Wumo::Wumo(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("wumo");
}

QUrl Wumo::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/img/wumo/[^\"]*)\"");
}
