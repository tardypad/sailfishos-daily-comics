/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef MACADAMVALLEY_H
#define MACADAMVALLEY_H

#include "../Comic.h"

class MacadamValley : public Comic
{
    Q_OBJECT

public:
    explicit MacadamValley(QString id, QObject *parent = 0);
};

#endif // MACADAMVALLEY_H
