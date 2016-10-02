/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef THEHATANDFAT_H
#define THEHATANDFAT_H

#include "../Comic.h"

class TheHatAndFat : public Comic
{
    Q_OBJECT

public:
    explicit TheHatAndFat(QString id, QObject *parent = 0);
};

#endif // THEHATANDFAT_H
