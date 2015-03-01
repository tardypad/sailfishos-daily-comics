/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Comic.h"

#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

#include "ComicDatabaseResource.h"

Comic::Comic(QObject *parent) :
    QObject(parent),
    m_currentStripUrl(QUrl()),
    m_currentReply(NULL),
    m_favorite(false),
    m_newStrip(false),
    m_error(false),
    m_fetching(false),
    m_lastStripFetchTime(QDateTime())
{
    m_networkManager = new QNetworkAccessManager(this);
    dbResource = ComicDatabaseResource::instance();
}

Comic::~Comic()
{
    delete m_currentReply;
    delete m_networkManager;
}

void Comic::load()
{
    dbResource->load(this);
}

void Comic::save()
{
    dbResource->save(this);
}

void Comic::fetchCurrentStripUrl()
{
    abortFetching();
    delete m_currentReply;
    m_currentReply = NULL;

    QNetworkRequest request(stripSourceUrl());
    m_currentReply = m_networkManager->get(request);

    emit fetchStarted();
    setFetching(true);

    connect(m_currentReply, SIGNAL(finished()), this, SLOT(parse()));
    connect(m_currentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SIGNAL(networkError()));
    connect(m_currentReply, SIGNAL(downloadProgress(qint64,qint64)), this, SIGNAL(downloadProgress(qint64,qint64)));

    connect(this, SIGNAL(networkError()), this, SLOT(flagError()));
    connect(this, SIGNAL(parsingError()), this, SLOT(flagError()));

    connect(m_currentReply, SIGNAL(finished()), this, SLOT(flagStoppedFetching()));
    connect(m_currentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(flagStoppedFetching()));
}

void Comic::abortFetching()
{
    if (m_currentReply != NULL && m_currentReply->isRunning()) {
        m_currentReply->disconnect(this);
        m_currentReply->abort();
    }
}

void Comic::read()
{
    setNewStrip(false);
    save();
}

void Comic::parse()
{
    if (m_currentReply->error() != QNetworkReply::NoError)
        return;

    QByteArray data = m_currentReply->readAll();
    QUrl stripUrl = extractStripUrl(data);

    if (!stripUrl.isValid()) {
        emit parsingError();
        return;
    }

    setError(false);

    if (stripUrl != currentStripUrl())
        setNewStrip(true);

    setCurrentStripUrl(stripUrl);
    setLastStripFetchTime(QDateTime::currentDateTime());

    save();

    emit dataParsed();
}

void Comic::flagError()
{
    setError(true);
}

void Comic::flagStoppedFetching()
{
    setFetching(false);
}
