/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef LUNARBABOON_H
#define LUNARBABOON_H

#include "../Comic.h"

class Lunarbaboon : public Comic
{
    Q_OBJECT

public:
    explicit Lunarbaboon(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // LUNARBABOON_H
