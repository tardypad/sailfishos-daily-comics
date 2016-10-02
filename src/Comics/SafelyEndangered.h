/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef SAFELYENDANGERED_H
#define SAFELYENDANGERED_H

#include "../Comic.h"

class SafelyEndangered : public Comic
{
    Q_OBJECT

public:
    explicit SafelyEndangered(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // SAFELYENDANGERED_H
