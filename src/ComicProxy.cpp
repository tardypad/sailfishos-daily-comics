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
    connect(this, SIGNAL(idChanged()), SIGNAL(nameChanged()));
    connect(this, SIGNAL(idChanged()), SIGNAL(authorsChanged()));
    connect(this, SIGNAL(idChanged()), SIGNAL(homepageChanged()));
    connect(this, SIGNAL(idChanged()), SIGNAL(countryChanged()));
    connect(this, SIGNAL(idChanged()), SIGNAL(languageChanged()));
    connect(this, SIGNAL(idChanged()), SIGNAL(stripImagePathChanged()));
    connect(this, SIGNAL(idChanged()), SIGNAL(stripImageUrlChanged()));
    connect(this, SIGNAL(idChanged()), SIGNAL(errorChanged()));
    connect(this, SIGNAL(idChanged()), SIGNAL(animatedChanged()));
}

QString ComicProxy::id() const
{
    return m_comic ? m_comic->id() : QString();
}

QString ComicProxy::name() const
{
    return m_comic ? m_comic->name() : QString();
}

QStringList ComicProxy::authors() const
{
    return m_comic ? m_comic->authors() : QStringList();
}

QUrl ComicProxy::homepage() const
{
    return m_comic ? m_comic->homepage() : QUrl();
}

QString ComicProxy::country() const
{
    return m_comic ? QLocale::countryToString(m_comic->country()) : "";
}

QString ComicProxy::language() const
{
    return m_comic ? QLocale::languageToString(m_comic->language()) : "";
}

QUrl ComicProxy::stripImagePath() const
{
    return m_comic ? m_comic->stripImagePath() : QUrl();
}

QUrl ComicProxy::stripImageUrl() const
{
    return m_comic ? m_comic->stripImageUrl() : QUrl();
}

bool ComicProxy::error() const
{
    return m_comic ? m_comic->error() : false;
}

bool ComicProxy::animated() const
{
    return m_comic ? m_comic->animated() : false;
}

void ComicProxy::setComic(Comic *comic)
{
    if (comic == NULL)
        return;

    m_comic = comic;

    emit idChanged();

    connect(m_comic, SIGNAL(fetchStarted()), this, SIGNAL(fetchStarted()));
    connect(m_comic, SIGNAL(fetchSucceeded()), this, SIGNAL(fetchSucceeded()));
    connect(m_comic, SIGNAL(networkError()), this, SIGNAL(networkError()));
    connect(m_comic, SIGNAL(parsingError()), this, SIGNAL(parsingError()));
    connect(m_comic, SIGNAL(savingError()), this, SIGNAL(savingError()));
    connect(m_comic, SIGNAL(downloadProgress(qint64,qint64)), this, SIGNAL(downloadProgress(qint64,qint64)));
    connect(m_comic, SIGNAL(fetchSucceeded()), this, SIGNAL(stripImagePathChanged()));
    connect(m_comic, SIGNAL(fetchSucceeded()), this, SIGNAL(stripImageUrlChanged()));
    connect(m_comic, SIGNAL(fetchSucceeded()), this, SIGNAL(animatedChanged()));
    connect(m_comic, SIGNAL(errorChanged(Comic*)), this, SIGNAL(errorChanged()));
}

void ComicProxy::fetch()
{
    if (m_comic) {
        m_comic->fetchStrip();
    }
}

void ComicProxy::abortFetching()
{
    if (m_comic) {
        m_comic->abortFetching();
    }
}

void ComicProxy::read()
{
    if (m_comic) {
        m_comic->read();
    }
}

void ComicProxy::setError()
{
    if (m_comic) {
        m_comic->setError(true);
    }
}
