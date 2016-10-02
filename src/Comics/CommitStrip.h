/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMMITSTRIP_H
#define COMMITSTRIP_H

#include "../Comic.h"

class CommitStrip : public Comic
{
    Q_OBJECT

public:
    explicit CommitStrip(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // COMMITSTRIP_H
