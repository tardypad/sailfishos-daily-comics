/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LupoAlberto.h"

#include <QDebug>

LupoAlberto::LupoAlberto(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl LupoAlberto::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "href=\"([^\"]*/tavola-settimana/[^\"]*)\"");
}
