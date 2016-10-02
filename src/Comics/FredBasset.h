/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef FREDBASSET_H
#define FREDBASSET_H

#include "../Comic.h"

class FredBasset : public Comic
{
    Q_OBJECT

public:
    explicit FredBasset(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // FREDBASSET_H
