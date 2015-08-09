/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef TUBEYTOONS_H
#define TUBEYTOONS_H

#include "../Comic.h"

class TubeyToons : public Comic
{
    Q_OBJECT

public:
    explicit TubeyToons(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // TUBEYTOONS_H
