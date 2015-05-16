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

const int Comic::_minFetchDelay = 1800;

Comic::Comic(QObject *parent) :
    QObject(parent),
    m_stripUrl(QUrl()),
    m_currentReply(NULL),
    m_favorite(false),
    m_newStrip(false),
    m_error(false),
    m_fetching(false),
    m_fetchTime(QDateTime())
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

void Comic::fetchStripUrl(QUrl stripUrl)
{
    if (!error() &&
        !fetchTime().isNull() &&
        QDateTime::currentDateTime().secsTo(fetchTime()) > -_minFetchDelay)
        return;

    abortFetching();
    delete m_currentReply;
    m_currentReply = NULL;

    QUrl requestUrl = !stripUrl.isEmpty() ? stripUrl : stripSourceUrl();
    QNetworkRequest request(requestUrl);
    m_currentReply = m_networkManager->get(request);

    emit fetchStarted();
    setFetching(true);

    connect(m_currentReply, SIGNAL(finished()), this, SLOT(onFetchFinished()));
    connect(m_currentReply, SIGNAL(downloadProgress(qint64,qint64)), this, SIGNAL(downloadProgress(qint64,qint64)));
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

void Comic::onFetchFinished()
{
    setFetching(false);

    if (m_currentReply->error() != QNetworkReply::NoError) {
        setError(true);
        emit networkError();
        return;
    }

    QVariant redirectAttribute = m_currentReply->attribute(QNetworkRequest::RedirectionTargetAttribute);

    if (redirectAttribute.isValid()) {
        QUrl redirectUrl = redirectAttribute.toUrl();
        if (redirectUrl.isRelative()) {
            redirectUrl = m_currentReply->url().resolved(redirectUrl);
        }
        fetchStripUrl(redirectUrl);
        return;
    }

    parse();
}

void Comic::parse()
{
    QByteArray data = m_currentReply->readAll();
    QUrl extractedStripUrl = extractStripUrl(data);

    if (!extractedStripUrl.isValid()) {
        setError(true);
        emit parsingError();
        return;
    }

    setError(false);

    if (extractedStripUrl != stripUrl())
        setNewStrip(true);

    setStripUrl(extractedStripUrl);
    setFetchTime(QDateTime::currentDateTime());

    save();

    emit dataParsed();
}
