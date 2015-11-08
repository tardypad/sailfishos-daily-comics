/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef FMINUS_H
#define FMINUS_H

#include "../Comic.h"

class FMinus : public Comic
{
    Q_OBJECT

public:
    explicit FMinus(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // FMINUS_H
