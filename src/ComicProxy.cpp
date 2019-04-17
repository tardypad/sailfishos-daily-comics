/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicProxy.h"

#include <QtDebug>

#include "Comic.h"
#include "ComicFactory.h"

ComicProxy::ComicProxy(QObject *parent) :
    QObject(parent),
    m_comic(NULL)
{
    connect(this, &ComicProxy::idChanged, &ComicProxy::nameChanged);
    connect(this, &ComicProxy::idChanged, &ComicProxy::authorsChanged);
    connect(this, &ComicProxy::idChanged, &ComicProxy::homepageChanged);
    connect(this, &ComicProxy::idChanged, &ComicProxy::languageChanged);
    connect(this, &ComicProxy::idChanged, &ComicProxy::stripImagePathChanged);
    connect(this, &ComicProxy::idChanged, &ComicProxy::stripImageUrlChanged);
    connect(this, &ComicProxy::idChanged, &ComicProxy::coverPathChanged);
    connect(this, &ComicProxy::idChanged, &ComicProxy::examplePathChanged);
    connect(this, &ComicProxy::idChanged, &ComicProxy::errorChanged);
    connect(this, &ComicProxy::idChanged, &ComicProxy::animatedChanged);
    connect(this, &ComicProxy::idChanged, &ComicProxy::stripImageDownloadedChanged);
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

QString ComicProxy::coverPath() const
{
    return m_comic ? m_comic->coverPath() : QString();
}

QString ComicProxy::examplePath() const
{
    return m_comic ? m_comic->examplePath() : QString();
}

bool ComicProxy::error() const
{
    return m_comic ? m_comic->error() : false;
}

bool ComicProxy::animated() const
{
    return m_comic ? m_comic->animated() : false;
}

Comic *ComicProxy::comic() const
{
    return m_comic;
}

bool ComicProxy::stripImageDownloaded() const
{
    return m_comic ? m_comic->stripImageDownloaded() : false;
}

void ComicProxy::setComic(Comic *comic)
{
    if (comic == NULL || m_comic == comic)
        return;

    m_comic = comic;

    connect(m_comic, &Comic::fetchStarted, this, &ComicProxy::fetchStarted);
    connect(m_comic, &Comic::fetchSucceeded, this, &ComicProxy::fetchSucceeded);
    connect(m_comic, &Comic::networkError, this, &ComicProxy::networkError);
    connect(m_comic, &Comic::parsingError, this, &ComicProxy::parsingError);
    connect(m_comic, &Comic::savingError, this, &ComicProxy::savingError);
    connect(m_comic, &Comic::downloadProgress, this, &ComicProxy::downloadProgress);
    connect(m_comic, &Comic::fetchSucceeded, this, &ComicProxy::stripImagePathChanged);
    connect(m_comic, &Comic::fetchSucceeded, this, &ComicProxy::stripImageUrlChanged);
    connect(m_comic, &Comic::fetchSucceeded, this, &ComicProxy::animatedChanged);
    connect(m_comic, &Comic::fetchSucceeded, this, &ComicProxy::stripImageDownloadedChanged);
    connect(m_comic, &Comic::errorChanged, this, &ComicProxy::errorChanged);

    emit idChanged();
    emit comicChanged();
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

bool ComicProxy::saveToGallery()
{
    return m_comic ? m_comic->saveToGallery() : false;
}
