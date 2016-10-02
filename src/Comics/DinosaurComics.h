/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef DINOSAURCOMICS_H
#define DINOSAURCOMICS_H

#include "../Comic.h"

class DinosaurComics : public Comic
{
    Q_OBJECT

public:
    explicit DinosaurComics(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // DINOSAURCOMICS_H
