/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef ANDYCAPP_H
#define ANDYCAPP_H

#include "../Comic.h"

class AndyCapp : public Comic
{
    Q_OBJECT

public:
    explicit AndyCapp(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // ANDYCAPP_H
