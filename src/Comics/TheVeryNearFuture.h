/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef THEVERYNEARFUTURE_H
#define THEVERYNEARFUTURE_H

#include "../Comic.h"

class TheVeryNearFuture : public Comic
{
    Q_OBJECT

public:
    explicit TheVeryNearFuture(QString id, QObject *parent = 0);
};

#endif // THEVERYNEARFUTURE_H
