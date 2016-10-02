/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef DRMCNINJA_H
#define DRMCNINJA_H

#include "../Comic.h"

class DrMcNinja : public Comic
{
    Q_OBJECT

public:
    explicit DrMcNinja(QString id, QObject *parent = 0);
};

#endif // DRMCNINJA_H
