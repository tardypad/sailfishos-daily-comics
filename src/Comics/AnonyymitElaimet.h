/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef ANONYYMITELAIMET_H
#define ANONYYMITELAIMET_H

#include "../Comic.h"

class AnonyymitElaimet : public Comic
{
    Q_OBJECT

public:
    explicit AnonyymitElaimet(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // ANONYYMITELAIMET_H
