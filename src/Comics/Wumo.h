/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef WUMO_H
#define WUMO_H

#include "../Comic.h"

class Wumo : public Comic
{
    Q_OBJECT

public:
    explicit Wumo(QString id, QObject *parent = 0);
};

#endif // WUMO_H
