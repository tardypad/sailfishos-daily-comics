/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PBFComics.h"

#include <QDebug>

PBFComics::PBFComics(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl PBFComics::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "src=&quot;([^&]*/archive_b/[^&]*)&quot;");
}
