/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef USERFRIENDLY_H
#define USERFRIENDLY_H

#include "../Comic.h"

class UserFriendly : public Comic
{
    Q_OBJECT

public:
    explicit UserFriendly(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // USERFRIENDLY_H
