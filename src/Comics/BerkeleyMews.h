/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef BERKELEYMEWS_H
#define BERKELEYMEWS_H

#include "../Comic.h"

class BerkeleyMews : public Comic
{
    Q_OBJECT

public:
    explicit BerkeleyMews(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // BERKELEYMEWS_H
