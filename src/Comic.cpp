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
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>
#include <QJSEngine>
#include <QJSValue>
#include <QJSValueList>
#include <QDir>
#include <QFile>

#include "ComicDatabaseResource.h"
#include "ComicInfoFileResource.h"
#include "ComicStripFileResource.h"

const int Comic::_minFetchDelay = 1800; // 30 min
const int Comic::_timeout = 30000; // 30 sec
const QString Comic::_coverFilename = "cover.jpg";
const QString Comic::_exampleFilename = "example.jpg";

QJSEngine* Comic::_jsEngine = new QJSEngine();

Comic::Comic(QString id, QObject *parent) :
    QObject(parent),
    m_id(id),
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
    m_coverPath = QDir(PLUGINS_FOLDER_PATH).path()
            .append(QDir::separator()).append(id)
            .append(QDir::separator()).append(_coverFilename);

    m_examplePath = QDir(PLUGINS_FOLDER_PATH).path()
            .append(QDir::separator()).append(id)
            .append(QDir::separator()).append(_exampleFilename);

    m_networkManager = new QNetworkAccessManager(this);
    infoFileResource = ComicInfoFileResource::instance();
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
    infoFileResource->load(this);
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
    QStringList prefixes = QStringList() << "the" << "le" << "une";
    QString prefix;

    for (int i = 0; i < prefixes.size(); ++i) {
        prefix = prefixes.at(i) + ' ';
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
    request.setHeader(QNetworkRequest::UserAgentHeader, "sailfishos/tardypad/dailycomics");
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
    QUrl extractedStripImageUrl = extractStripImageUrl(data);

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

QUrl Comic::extractStripImageUrl(QByteArray data)
{
    QString scriptFilePath = QString(PLUGINS_FOLDER_PATH) + "/" + id() + "/extract.js";
    QFile* scriptFile = new QFile();
    scriptFile->setFileName(scriptFilePath);

    if (!scriptFile->open(QIODevice::ReadOnly))
    {
        return QUrl();
    }

    QString script = QString(scriptFile->readAll());

    scriptFile->close();
    scriptFile->deleteLater();

    QJSValue function = _jsEngine->evaluate(script);
    QJSValue result = function.call(QJSValueList() << QString(data));

    QUrl src = result.toVariant().toUrl();

    if (src.isRelative())
        return m_currentReply->url().resolved(src);

    return src;
}

void Comic::fetchStripImage(QUrl stripImageUrl)
{
    delete m_currentReply;
    m_currentReply = NULL;

    QNetworkRequest request(stripImageUrl);
    request.setHeader(QNetworkRequest::UserAgentHeader, "sailfishos/tardypad/dailycomics");
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
