/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef DENNISTHEMENACE_H
#define DENNISTHEMENACE_H

#include "../Comic.h"

class DennisTheMenace : public Comic
{
    Q_OBJECT

public:
    explicit DennisTheMenace(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // DENNISTHEMENACE_H
