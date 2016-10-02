/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef VIIVIJAWAGNER_H
#define VIIVIJAWAGNER_H

#include "../Comic.h"

class ViiviJaWagner : public Comic
{
    Q_OBJECT

public:
    explicit ViiviJaWagner(QString id, QObject *parent = 0);
};

#endif // VIIVIJAWAGNER_H
