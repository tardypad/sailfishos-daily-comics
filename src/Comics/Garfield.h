/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef GARFIELD_H
#define GARFIELD_H

#include "../Comic.h"

class Garfield : public Comic
{
    Q_OBJECT

public:
    explicit Garfield(QObject *parent = 0);

    virtual inline QString id() const { return _id; }
    virtual inline QString name() const { return _name; }
    virtual inline QString author() const { return _author; }
    virtual inline QUrl homepage() const { return _homepage; }

    virtual QUrl getCurrentStripUrl();

protected:
    virtual inline QUrl stripSourceUrl() const { return _stripSourceUrl; }

private:
    static const QString _id;
    static const QString _name;
    static const QString _author;
    static const QUrl _homepage;
    static const QUrl _stripSourceUrl;
};

#endif // GARFIELD_H
