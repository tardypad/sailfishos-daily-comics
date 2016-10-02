/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef UNEANNEEAULYCEE_H
#define UNEANNEEAULYCEE_H

#include "../Comic.h"

class UneAnneeAuLycee : public Comic
{
    Q_OBJECT

public:
    explicit UneAnneeAuLycee(QString id, QObject *parent = 0);
};

#endif // UNEANNEEAULYCEE_H
