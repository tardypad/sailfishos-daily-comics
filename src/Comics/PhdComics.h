/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef PHPCOMICS_H
#define PHPCOMICS_H

#include "../Comic.h"

class PhdComics : public Comic
{
    Q_OBJECT

public:
    explicit PhdComics(QString id, QObject *parent = 0);
};

#endif // PHPCOMICS_H
