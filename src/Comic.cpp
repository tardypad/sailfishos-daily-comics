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
#include <QImageReader>

#include "ComicDatabaseResource.h"
#include "ComicPluginResource.h"
#include "ComicStripFileResource.h"

const int Comic::_minFetchDelay = 1800; // 30 min
const int Comic::_timeout = 30000; // 30 sec
const QStringList Comic::_prefixes = QStringList() << "the" << "le" << "une";

Comic::Comic(QString id, QObject *parent) :
    QObject(parent),
    m_id(id),
    m_coverPath(""),
    m_examplePath(""),
    m_info(ComicInfo()),
    m_currentReply(NULL),
    m_random(rand()),
    m_extractedStripImageUrl(QUrl()),
    m_stripImageUrl(QUrl()),
    m_favorite(false),
    m_newStrip(false),
    m_error(false),
    m_fetching(false),
    m_fetchTime(QDateTime()),
    m_fetchingProgress(0),
    m_animated(false),
    m_isAnimatedDefined(false)
{
    m_networkManager = new QNetworkAccessManager(this);
    pluginResource = ComicPluginResource::instance();
    dbResource = ComicDatabaseResource::instance();
    stripFileResource = ComicStripFileResource::instance();

    m_timeoutTimer = new QTimer(this);
    m_timeoutTimer->setInterval(_timeout);
    m_timeoutTimer->setSingleShot(true);
    connect(m_timeoutTimer, SIGNAL(timeout()), this, SLOT(timeout()));
}

Comic::~Comic()
{
    delete m_currentReply;
    delete m_networkManager;
    delete m_timeoutTimer;
}

void Comic::load()
{
    pluginResource->load(this);
    dbResource->load(this);
}

void Comic::save()
{
    dbResource->save(this);
}

QString Comic::stripImagePath() const
{
     return stripFileResource->path(id());
}

bool Comic::animated()
{
    if (!isAnimatedDefined()) {
        QImageReader imageReader(stripImagePath());
        QByteArray format = imageReader.format();
        m_animated = (!format.isEmpty() && format == "gif");
        setIsAnimatedDefined(true);
    }

    return m_animated;
}

QString Comic::sortName() const
{
    QString lowerName = name().toLower();
    QString prefix;

    for (int i = 0; i < _prefixes.size(); ++i) {
        prefix = _prefixes.at(i) + ' ';
        if (lowerName.startsWith(prefix))
            return lowerName.remove(0, prefix.size());
    }

    return lowerName;
}

void Comic::fetchStrip()
{
    if (!error() &&
        !fetchTime().isNull() &&
        QDateTime::currentDateTime().secsTo(fetchTime()) > -_minFetchDelay &&
        stripImageDownloaded())
        return;

    abortFetching();
    fetchStripSource();
}

void Comic::fetchStripSource(QUrl stripSrcUrl)
{
    delete m_currentReply;
    m_currentReply = NULL;

    QUrl requestUrl = !stripSrcUrl.isEmpty() ? stripSrcUrl : stripSourceUrl();
    QNetworkRequest request(requestUrl);
    request.setHeader(QNetworkRequest::UserAgentHeader, "sailfishos/tardypad/dailycomics curl");
    m_currentReply = m_networkManager->get(request);

    m_timeoutTimer->start();
    emit fetchStarted();
    setFetching(true);
    setFetchingProgress(0);

    connect(m_currentReply, SIGNAL(finished()), this, SLOT(onFetchStripSourceFinished()));
    connect(m_currentReply, SIGNAL(downloadProgress(qint64,qint64)), this, SIGNAL(downloadProgress(qint64,qint64)));
    connect(m_currentReply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(updateFetchingProgress(qint64,qint64)));
}

void Comic::abortFetching()
{
    setFetching(false);

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

bool Comic::stripImageDownloaded()
{
    return stripFileResource->isDownloaded(id());
}

QUrl Comic::redirectedToUrl()
{
    QVariant redirectAttribute = m_currentReply->attribute(QNetworkRequest::RedirectionTargetAttribute);

    if (redirectAttribute.isValid()) {
        QUrl redirectUrl = redirectAttribute.toUrl();

        if (redirectUrl.isRelative())
            redirectUrl = m_currentReply->url().resolved(redirectUrl);

        return redirectUrl;
    }

    return QUrl();
}

void Comic::onFetchStripSourceFinished()
{
    m_timeoutTimer->stop();

    if (m_currentReply->error() != QNetworkReply::NoError) {
        setFetching(false);
        setError(true);
        emit networkError();
        return;
    }

    QUrl redirectUrl = redirectedToUrl();

    if (!redirectUrl.isEmpty()) {
        fetchStripSource(redirectUrl);
        return;
    }

    QByteArray data = m_currentReply->readAll();
    QUrl extractedStripImageUrl = pluginResource->extractStripImageUrl(this, data);

    if (extractedStripImageUrl.isRelative())
        extractedStripImageUrl = m_currentReply->url().resolved(extractedStripImageUrl);

    if (!extractedStripImageUrl.isValid()) {
        setFetching(false);
        setError(true);
        emit parsingError();
        return;
    }

    setExtractedStripImageUrl(extractedStripImageUrl);

    if (extractedStripImageUrl != stripImageUrl() || !stripImageDownloaded()) {
        fetchStripImage(extractedStripImageUrl);
    } else {
        setFetching(false);
        setError(false);
        emit fetchSucceeded();
        setStripImageUrl(extractedStripImageUrl);
        setFetchTime(QDateTime::currentDateTime());
        save();
    }
}

void Comic::fetchStripImage(QUrl stripImageUrl)
{
    delete m_currentReply;
    m_currentReply = NULL;

    QNetworkRequest request(stripImageUrl);
    request.setHeader(QNetworkRequest::UserAgentHeader, "sailfishos/tardypad/dailycomics curl");
    m_currentReply = m_networkManager->get(request);

    m_timeoutTimer->start();

    connect(m_currentReply, SIGNAL(finished()), this, SLOT(onFetchStripImageFinished()));
    connect(m_currentReply, SIGNAL(downloadProgress(qint64,qint64)), this, SIGNAL(downloadProgress(qint64,qint64)));
    connect(m_currentReply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(updateFetchingProgress(qint64,qint64)));
}

void Comic::onFetchStripImageFinished()
{
    m_timeoutTimer->stop();

    if (m_currentReply->error() != QNetworkReply::NoError) {
        setFetching(false);
        setError(true);
        emit networkError();
        return;
    }

    QUrl redirectUrl = redirectedToUrl();

    if (!redirectUrl.isEmpty()) {
        fetchStripImage(redirectUrl);
        return;
    }

    QByteArray data = m_currentReply->readAll();
    bool result = stripFileResource->save(id(), data);

    if (!result) {
        setFetching(false);
        setError(true);
        emit savingError();
        return;
    }

    if (extractedStripImageUrl() != stripImageUrl()) {
        setNewStrip(true);
    }

    setFetching(false);
    setError(false);
    setIsAnimatedDefined(false);
    emit fetchSucceeded();
    setStripImageUrl(extractedStripImageUrl());
    setFetchTime(QDateTime::currentDateTime());
    save();
}

void Comic::timeout()
{
    abortFetching();
    setError(true);
    emit networkError();
}

void Comic::updateFetchingProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    if (bytesTotal != 0)
        setFetchingProgress(bytesReceived / bytesTotal);
    else
        setFetchingProgress(0);
}
