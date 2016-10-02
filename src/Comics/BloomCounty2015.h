/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef BLOOMCOUNTY2015_H
#define BLOOMCOUNTY2015_H

#include "../Comic.h"

class BloomCounty2015 : public Comic
{
    Q_OBJECT

public:
    explicit BloomCounty2015(QString id, QObject *parent = 0);
};

#endif // BLOOMCOUNTY2015_H
