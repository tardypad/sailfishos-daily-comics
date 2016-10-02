/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef FOKIT_H
#define FOKIT_H

#include "../Comic.h"

class FokIt : public Comic
{
    Q_OBJECT

public:
    explicit FokIt(QString id, QObject *parent = 0);
};

#endif // FOKIT_H
