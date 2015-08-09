/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef FOKIT_H
#define FOKIT_H

#include "../Comic.h"

class FokIt : public Comic
{
    Q_OBJECT

public:
    explicit FokIt(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // FOKIT_H
