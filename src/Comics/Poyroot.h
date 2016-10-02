/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef POYROOT_H
#define POYROOT_H

#include "../Comic.h"

class Poyroot : public Comic
{
    Q_OBJECT

public:
    explicit Poyroot(QString id, QObject *parent = 0);
};

#endif // POYROOT_H
