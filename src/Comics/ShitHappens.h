/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef SHITHAPPENS_H
#define SHITHAPPENS_H

#include "../Comic.h"

class ShitHappens : public Comic
{
    Q_OBJECT

public:
    explicit ShitHappens(QString id, QObject *parent = 0);
};

#endif // SHITHAPPENS_H
