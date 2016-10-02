/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef SWAMP_H
#define SWAMP_H

#include "../Comic.h"

class Swamp : public Comic
{
    Q_OBJECT

public:
    explicit Swamp(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // SWAMP_H
