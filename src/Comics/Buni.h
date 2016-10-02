/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef BUNI_H
#define BUNI_H

#include "../Comic.h"

class Buni : public Comic
{
    Q_OBJECT

public:
    explicit Buni(QString id, QObject *parent = 0);
};

#endif // BUNI_H
