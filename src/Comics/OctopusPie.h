/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef OCTOPUSPIE_H
#define OCTOPUSPIE_H

#include "../Comic.h"

class OctopusPie : public Comic
{
    Q_OBJECT

public:
    explicit OctopusPie(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // OCTOPUSPIE_H
