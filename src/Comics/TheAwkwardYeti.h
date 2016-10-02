/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef THEAWKWARDYETI_H
#define THEAWKWARDYETI_H

#include "../Comic.h"

class TheAwkwardYeti : public Comic
{
    Q_OBJECT

public:
    explicit TheAwkwardYeti(QString id, QObject *parent = 0);
};

#endif // THEAWKWARDYETI_H
