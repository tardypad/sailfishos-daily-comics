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
    connect(this, SIGNAL(comicIdChanged()), SIGNAL(countryChanged()));
    connect(this, SIGNAL(comicIdChanged()), SIGNAL(languageChanged()));
    connect(this, SIGNAL(comicIdChanged()), SIGNAL(startDateChanged()));
    connect(this, SIGNAL(comicIdChanged()), SIGNAL(endDateChanged()));
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

QString ComicProxy::country() const
{
    return m_comic ? QLocale::countryToString(m_comic->country()) : "";
}

QString ComicProxy::language() const
{
    return m_comic ? QLocale::languageToString(m_comic->language()) : "";
}

QDate ComicProxy::startDate() const
{
    return m_comic ? m_comic->startDate() : QDate();
}

QDate ComicProxy::endDate() const
{
    return m_comic ? m_comic->endDate() : QDate();
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

    connect(m_comic, SIGNAL(fetchStarted()), this, SIGNAL(fetchStarted()));
    connect(m_comic, SIGNAL(dataParsed()), this, SIGNAL(dataParsed()));
    connect(m_comic, SIGNAL(networkError()), this, SIGNAL(networkError()));
    connect(m_comic, SIGNAL(parsingError()), this, SIGNAL(parsingError()));
    connect(m_comic, SIGNAL(downloadProgress(qint64,qint64)), this, SIGNAL(downloadProgress(qint64,qint64)));
    connect(m_comic, SIGNAL(dataParsed()), this, SIGNAL(currentStripUrlChanged()));
}

void ComicProxy::fetch()
{
    if (m_comic) {
        m_comic->fetchCurrentStripUrl();
    }
}

void ComicProxy::abortFetching()
{
    if (m_comic) {
        m_comic->abortFetching();
    }
}
