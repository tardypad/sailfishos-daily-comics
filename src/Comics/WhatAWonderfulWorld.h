/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef WHATAWONDERFULWORLD_H
#define WHATAWONDERFULWORLD_H

#include "../Comic.h"

class WhatAWonderfulWorld : public Comic
{
    Q_OBJECT

public:
    explicit WhatAWonderfulWorld(QString id, QObject *parent = 0);
};

#endif // WHATAWONDERFULWORLD_H
