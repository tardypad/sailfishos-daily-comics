/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef DERFLIX_H
#define DERFLIX_H

#include "../Comic.h"

class DerFlix : public Comic
{
    Q_OBJECT

public:
    explicit DerFlix(QString id, QObject *parent = 0);
};

#endif // DERFLIX_H
