/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef LUNARBABOON_H
#define LUNARBABOON_H

#include "../Comic.h"

class Lunarbaboon : public Comic
{
    Q_OBJECT

public:
    explicit Lunarbaboon(QString id, QObject *parent = 0);
};

#endif // LUNARBABOON_H
