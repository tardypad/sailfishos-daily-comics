/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef LUPOALBERTO_H
#define LUPOALBERTO_H

#include "../Comic.h"

class LupoAlberto : public Comic
{
    Q_OBJECT

public:
    explicit LupoAlberto(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // LUPOALBERTO_H
