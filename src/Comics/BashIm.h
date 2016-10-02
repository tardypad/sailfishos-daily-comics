/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef BASHIM_H
#define BASHIM_H

#include "../Comic.h"

class BashIm : public Comic
{
    Q_OBJECT

public:
    explicit BashIm(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // BASHIM_H
