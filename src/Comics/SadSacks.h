/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef SADSACKS_H
#define SADSACKS_H

#include "../Comic.h"

class SadSacks : public Comic
{
    Q_OBJECT

public:
    explicit SadSacks(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // SADSACKS_H
