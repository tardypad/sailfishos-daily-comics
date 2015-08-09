/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef CALVINANDHOBBES_H
#define CALVINANDHOBBES_H

#include "../Comic.h"

class CalvinAndHobbes : public Comic
{
    Q_OBJECT

public:
    explicit CalvinAndHobbes(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // CALVINANDHOBBES_H
