/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef LUNCH_H
#define LUNCH_H

#include "../Comic.h"

class Lunch : public Comic
{
    Q_OBJECT

public:
    explicit Lunch(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // LUNCH_H
