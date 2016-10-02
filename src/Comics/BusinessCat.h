/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef BUSINESSCAT_H
#define BUSINESSCAT_H

#include "../Comic.h"

class BusinessCat : public Comic
{
    Q_OBJECT

public:
    explicit BusinessCat(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // BUSINESSCAT_H
