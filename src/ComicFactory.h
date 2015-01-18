/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMICFACTORY_H
#define COMICFACTORY_H

#include "Comic.h"

class ComicFactory
{
public:
    static Comic *create(QString id, QObject *parent = 0);
};

#endif // COMICFACTORY_H
