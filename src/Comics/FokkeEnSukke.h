/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef FOKKEENSUKKE_H
#define FOKKEENSUKKE_H

#include "../Comic.h"

class FokkeEnSukke : public Comic
{
    Q_OBJECT

public:
    explicit FokkeEnSukke(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // FOKKEENSUKKE_H
