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
    explicit ViiviJaWagner(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // VIIVIJAWAGNER_H
