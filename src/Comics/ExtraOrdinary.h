/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef EXTRAORDINARY_H
#define EXTRAORDINARY_H

#include "../Comic.h"

class ExtraOrdinary : public Comic
{
    Q_OBJECT

public:
    explicit ExtraOrdinary(QString id, QObject *parent = 0);
};

#endif // EXTRAORDINARY_H
