/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef SINFEST_H
#define SINFEST_H

#include "../Comic.h"

class Sinfest : public Comic
{
    Q_OBJECT

public:
    explicit Sinfest(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // SINFEST_H
