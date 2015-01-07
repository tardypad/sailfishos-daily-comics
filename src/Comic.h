/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMIC_H
#define COMIC_H

#include <QObject>

#include <QUrl>

class Comic : public QObject
{
    Q_OBJECT

public:
    explicit Comic(QObject *parent = 0);

    virtual QString id() const = 0;
    virtual QString name() const = 0;
    virtual QString author() const = 0;
    virtual QUrl url() const = 0;

protected:
    virtual QUrl stripUrl() const = 0;
};

#endif // COMIC_H
