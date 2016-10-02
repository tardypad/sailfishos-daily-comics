/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef NAMELESSPCS_H
#define NAMELESSPCS_H

#include "../Comic.h"

class NamelessPcs : public Comic
{
    Q_OBJECT

public:
    explicit NamelessPcs(QString id, QObject *parent = 0);
};

#endif // NAMELESSPCS_H
