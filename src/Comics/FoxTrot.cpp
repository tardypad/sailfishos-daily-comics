/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FoxTrot.h"

#include <QDebug>

FoxTrot::FoxTrot(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("foxtrot");
}

QUrl FoxTrot::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
