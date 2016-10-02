/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef GARFIELD_H
#define GARFIELD_H

#include "../Comic.h"

class Garfield : public Comic
{
    Q_OBJECT

public:
    explicit Garfield(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // GARFIELD_H
