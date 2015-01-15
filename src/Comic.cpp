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

Comic::Comic(QObject *parent) :
    QObject(parent),
    m_currentStripUrl(QUrl()),
    m_currentReply(NULL),
    m_favorite(false),
    m_newStrip(false)
{
    m_networkManager = new QNetworkAccessManager(this);
}

Comic::~Comic()
{
    delete m_currentReply;
    delete m_networkManager;
}

void Comic::fetchCurrentStripUrl()
{
    abortFetching();
    delete m_currentReply;
    m_currentReply = NULL;

    QNetworkRequest request(stripSourceUrl());
    m_currentReply = m_networkManager->get(request);

    emit fetchStarted();

    connect(m_currentReply, SIGNAL(finished()), this, SLOT(parse()));
    connect(m_currentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SIGNAL(networkError()));
    connect(m_currentReply, SIGNAL(downloadProgress(qint64,qint64)), this, SIGNAL(downloadProgress(qint64,qint64)));
}

void Comic::abortFetching()
{
    if (m_currentReply != NULL && m_currentReply->isRunning()) {
        m_currentReply->disconnect(this);
        m_currentReply->abort();
    }
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

    setCurrentStripUrl(stripUrl);
    setNewStrip(true);

    emit dataParsed();
}
