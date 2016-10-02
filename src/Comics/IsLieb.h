/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef ISLIEB_H
#define ISLIEB_H

#include "../Comic.h"

class IsLieb : public Comic
{
    Q_OBJECT

public:
    explicit IsLieb(QString id, QObject *parent = 0);
};

#endif // ISLIEB_H
