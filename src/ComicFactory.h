/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMICFACTORY_H
#define COMICFACTORY_H

#include <QObject>

#include "Comic.h"

class ComicFactory : public QObject
{
    Q_OBJECT

public:
    static ComicFactory* instance();
    Comic *create(QString id, QObject *parent = 0);
    QStringList fullList() const;

    template <typename T>
    void registerComic(QString id)
    {
        m_map[id] = &createFunc<T>;
    }

private:
    explicit ComicFactory(QObject *parent = 0);

    template <typename T>
    static Comic* createFunc(QString id, QObject* parent = 0)
    {
        return new T(id, parent);
    }

private:
    static ComicFactory* m_instance;
    typedef Comic* (*PCreateFunc)(QString, QObject*);
    QMap<QString, PCreateFunc> m_map;
};

#endif // COMICFACTORY_H
