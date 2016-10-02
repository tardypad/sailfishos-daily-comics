/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef PIGKNIT_H
#define PIGKNIT_H

#include "../Comic.h"

class Pigknit : public Comic
{
    Q_OBJECT

public:
    explicit Pigknit(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // PIGKNIT_H
