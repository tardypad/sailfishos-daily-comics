/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef SMBC_H
#define SMBC_H

#include "../Comic.h"

class Smbc : public Comic
{
    Q_OBJECT

public:
    explicit Smbc(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // SMBC_H
