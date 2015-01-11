/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef DENNISTHEMENACE_H
#define DENNISTHEMENACE_H

#include "../Comic.h"

class DennisTheMenace : public Comic
{
    Q_OBJECT

public:
    explicit DennisTheMenace(QObject *parent = 0);

    virtual inline QString id() const { return _id; }
    virtual inline QString name() const { return _name; }
    virtual inline QString author() const { return _author; }
    virtual inline QUrl homepage() const { return _homepage; }

    virtual QUrl extractStripUrl(QByteArray data);

protected:
    virtual inline QUrl stripSourceUrl() const { return _stripSourceUrl; }

private:
    static const QString _id;
    static const QString _name;
    static const QString _author;
    static const QUrl _homepage;
    static const QUrl _stripSourceUrl;
};

#endif // DENNISTHEMENACE_H
