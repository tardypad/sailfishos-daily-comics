/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef DARTHSANDDROIDS_H
#define DARTHSANDDROIDS_H

#include "../Comic.h"

class DarthsAndDroids : public Comic
{
    Q_OBJECT

public:
    explicit DarthsAndDroids(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // DARTHSANDDROIDS_H
