/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "HagarTheHorrible.h"

#include <QDebug>

HagarTheHorrible::HagarTheHorrible(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("hagarthehorrible");
}

QUrl HagarTheHorrible::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*content\\.php[^\"]*)\"");
}
