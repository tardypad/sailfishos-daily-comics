/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef ERZAEHLMIRNIX_H
#define ERZAEHLMIRNIX_H

#include "../Comic.h"

class Erzaehlmirnix : public Comic
{
    Q_OBJECT

public:
    explicit Erzaehlmirnix(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // ERZAEHLMIRNIX_H
