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
    explicit UneAnneeAuLycee(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // UNEANNEEAULYCEE_H
