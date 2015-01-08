/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicProxy.h"

#include "Comic.h"
#include "ComicFactory.h"

ComicProxy::ComicProxy(QObject *parent) :
    QObject(parent),
    m_comic(NULL)
{
    connect(this, SIGNAL(comicIdChanged()), SIGNAL(nameChanged()));
    connect(this, SIGNAL(comicIdChanged()), SIGNAL(authorChanged()));
    connect(this, SIGNAL(comicIdChanged()), SIGNAL(homepageChanged()));
    connect(this, SIGNAL(comicIdChanged()), SIGNAL(currentStripUrlChanged()));
}

QString ComicProxy::comicId() const
{
    return m_comic ? m_comic->id() : QString();
}

QString ComicProxy::name() const
{
    return m_comic ? m_comic->name() : QString();
}

QString ComicProxy::author() const
{
    return m_comic ? m_comic->author() : QString();
}

QUrl ComicProxy::homepage() const
{
    return m_comic ? m_comic->homepage() : QUrl();
}

QUrl ComicProxy::currentStripUrl()
{
    return m_comic ? m_comic->currentStripUrl() : QUrl();
}

void ComicProxy::setComicId(const QString comicId)
{
    delete m_comic;
    m_comic = ComicFactory::create(comicId);
    emit comicIdChanged();
    connect(m_comic, SIGNAL(currentStripUrlFetched()), this, SIGNAL(currentStripUrlChanged()));
}

void ComicProxy::fetchCurrentStrip()
{
    if (m_comic) {
        m_comic->fetchCurrentStripUrl();
    }
}
