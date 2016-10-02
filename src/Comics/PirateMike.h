/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef PIRATEMIKE_H
#define PIRATEMIKE_H

#include "../Comic.h"

class PirateMike : public Comic
{
    Q_OBJECT

public:
    explicit PirateMike(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // PIRATEMIKE_H
