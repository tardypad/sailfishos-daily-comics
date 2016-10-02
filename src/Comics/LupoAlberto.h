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
    explicit LupoAlberto(QString id, QObject *parent = 0);
};

#endif // LUPOALBERTO_H
