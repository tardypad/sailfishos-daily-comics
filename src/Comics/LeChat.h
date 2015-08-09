/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef LECHAT_H
#define LECHAT_H

#include "../Comic.h"

class LeChat : public Comic
{
    Q_OBJECT

public:
    explicit LeChat(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // LECHAT_H
