/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef NEDROIDPICTUREDIARY_H
#define NEDROIDPICTUREDIARY_H

#include "../Comic.h"

class NedroidPictureDiary : public Comic
{
    Q_OBJECT

public:
    explicit NedroidPictureDiary(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // NEDROIDPICTUREDIARY_H
