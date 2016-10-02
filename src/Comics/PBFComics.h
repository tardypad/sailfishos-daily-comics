/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef PBFCOMICS_H
#define PBFCOMICS_H

#include "../Comic.h"

class PBFComics : public Comic
{
    Q_OBJECT

public:
    explicit PBFComics(QString id, QObject *parent = 0);
};

#endif // PBFCOMICS_H
