/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef KAMALALUONTO_H
#define KAMALALUONTO_H

#include "../Comic.h"

class KamalaLuonto : public Comic
{
    Q_OBJECT

public:
    explicit KamalaLuonto(QString id, QObject *parent = 0);
};

#endif // KAMALALUONTO_H
