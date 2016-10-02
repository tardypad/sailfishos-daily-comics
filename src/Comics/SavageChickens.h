/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef SAVAGECHICKENS_H
#define SAVAGECHICKENS_H

#include "../Comic.h"

class SavageChickens : public Comic
{
    Q_OBJECT

public:
    explicit SavageChickens(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // SAVAGECHICKENS_H
