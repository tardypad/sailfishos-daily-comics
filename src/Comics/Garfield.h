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
    virtual inline QUrl url() const { return _url; }

    virtual QUrl getCurrentStripUrl();

protected:
    virtual inline QUrl stripUrl() const { return _stripUrl; }

private:
    static const QString _id;
    static const QString _name;
    static const QString _author;
    static const QUrl _url;
    static const QUrl _stripUrl;
};

#endif // GARFIELD_H
