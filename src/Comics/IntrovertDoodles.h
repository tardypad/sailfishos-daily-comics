/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef INTROVERTDOODLES_H
#define INTROVERTDOODLES_H

#include "../Comic.h"

class IntrovertDoodles : public Comic
{
    Q_OBJECT

public:
    explicit IntrovertDoodles(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // INTROVERTDOODLES_H
