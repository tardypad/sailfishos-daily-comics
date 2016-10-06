/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicFactory.h"

#include <QDebug>
#include <QDir>

ComicFactory* ComicFactory::m_instance = NULL;

ComicFactory::ComicFactory(QObject *parent) :
    QObject(parent),
    m_list(QStringList())
{
    discoverComics();
}

ComicFactory* ComicFactory::instance()
{
    if (!m_instance) {
        m_instance = new ComicFactory();
    }

    return m_instance;
}

void ComicFactory::discoverComics()
{
    QDir pluginsDir(PLUGINS_FOLDER_PATH);

    m_list = pluginsDir.entryList(QDir::AllDirs | QDir::NoDotAndDotDot);
}

Comic *ComicFactory::create(QString id, QObject *parent)
{
    if (!m_list.contains(id))
        return NULL;

    return new Comic(id, parent);
}

QStringList ComicFactory::fullList() const
{
    return m_list;
}
