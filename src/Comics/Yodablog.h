/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef YODABLOG_H
#define YODABLOG_H

#include "../Comic.h"

class Yodablog : public Comic
{
    Q_OBJECT

public:
    explicit Yodablog(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // YODABLOG_H
