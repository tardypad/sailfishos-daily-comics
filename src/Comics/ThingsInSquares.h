/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef THINGSINSQUARES_H
#define THINGSINSQUARES_H

#include "../Comic.h"

class ThingsInSquares : public Comic
{
    Q_OBJECT

public:
    explicit ThingsInSquares(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // THINGSINSQUARES_H
