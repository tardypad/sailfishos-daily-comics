/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef THEWHITEBOARD_H
#define THEWHITEBOARD_H

#include "../Comic.h"

class TheWhiteboard : public Comic
{
    Q_OBJECT

public:
    explicit TheWhiteboard(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // THEWHITEBOARD_H
