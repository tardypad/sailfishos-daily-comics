/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef DIESELSWEETIES_H
#define DIESELSWEETIES_H

#include "../Comic.h"

class DieselSweeties : public Comic
{
    Q_OBJECT

public:
    explicit DieselSweeties(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // DIESELSWEETIES_H
