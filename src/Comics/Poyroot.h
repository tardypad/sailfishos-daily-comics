/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef POYROOT_H
#define POYROOT_H

#include "../Comic.h"

class Poyroot : public Comic
{
    Q_OBJECT

public:
    explicit Poyroot(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // POYROOT_H
