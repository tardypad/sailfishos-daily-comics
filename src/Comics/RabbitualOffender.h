/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef RABBITUALOFFENDER_H
#define RABBITUALOFFENDER_H

#include "../Comic.h"

class RabbitualOffender : public Comic
{
    Q_OBJECT

public:
    explicit RabbitualOffender(QString id, QObject *parent = 0);
};

#endif // RABBITUALOFFENDER_H
