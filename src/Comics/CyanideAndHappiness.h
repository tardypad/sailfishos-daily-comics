/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef CYANIDEANDHAPPINESS_H
#define CYANIDEANDHAPPINESS_H

#include "../Comic.h"

class CyanideAndHappiness : public Comic
{
    Q_OBJECT

public:
    explicit CyanideAndHappiness(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // CYANIDEANDHAPPINESS_H
