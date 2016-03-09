/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef LWHAG_H
#define LWHAG_H

#include "../Comic.h"

class Lwhag : public Comic
{
    Q_OBJECT

public:
    explicit Lwhag(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // LWHAG_H
