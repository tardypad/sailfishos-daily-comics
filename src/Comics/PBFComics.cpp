/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PBFComics.h"

#include <QDebug>

PBFComics::PBFComics(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("pbfcomics");
}

QUrl PBFComics::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "src=&quot;([^&]*/archive_b/[^&]*)&quot;");
}
