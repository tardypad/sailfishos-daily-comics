/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef CHEERUPEMOKID_H
#define CHEERUPEMOKID_H

#include "../Comic.h"

class CheerUpEmoKid : public Comic
{
    Q_OBJECT

public:
    explicit CheerUpEmoKid(QString id, QObject *parent = 0);
};

#endif // CHEERUPEMOKID_H
