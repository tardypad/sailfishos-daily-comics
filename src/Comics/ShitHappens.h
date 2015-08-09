/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef SHITHAPPENS_H
#define SHITHAPPENS_H

#include "../Comic.h"

class ShitHappens : public Comic
{
    Q_OBJECT

public:
    explicit ShitHappens(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // SHITHAPPENS_H
