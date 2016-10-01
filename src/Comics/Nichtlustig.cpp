/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Nichtlustig.h"

#include <QDebug>

Nichtlustig::Nichtlustig(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("nichtlustig");
}

QUrl Nichtlustig::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<link rel=\"image_src\" href=\"([^\"]*)\"");
}
