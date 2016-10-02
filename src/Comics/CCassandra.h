/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef CCASSANDRA_H
#define CCASSANDRA_H

#include "../Comic.h"

class CCassandra : public Comic
{
    Q_OBJECT

public:
    explicit CCassandra(QString id, QObject *parent = 0);
};

#endif // CCASSANDRA_H
