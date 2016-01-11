/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef EINBILDER_H
#define EINBILDER_H

#include "../Comic.h"

class Einbilder : public Comic
{
    Q_OBJECT

public:
    explicit Einbilder(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // EINBILDER_H
