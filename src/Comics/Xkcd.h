/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef XKCD_H
#define XKCD_H

#include "../Comic.h"

class Xkcd : public Comic
{
    Q_OBJECT

public:
    explicit Xkcd(QString id, QObject *parent = 0);
};

#endif // XKCD_H
