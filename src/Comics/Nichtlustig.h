/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef NICHTLUSTIG_H
#define NICHTLUSTIG_H

#include "../Comic.h"

class Nichtlustig : public Comic
{
    Q_OBJECT

public:
    explicit Nichtlustig(QString id, QObject *parent = 0);
};

#endif // NICHTLUSTIG_H
