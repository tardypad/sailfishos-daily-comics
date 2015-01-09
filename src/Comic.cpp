/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Comic.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

Comic::Comic(QObject *parent) :
    QObject(parent),
    m_currentStripUrl(QUrl()),
    m_currentReply(NULL),
    m_selected(false)
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
    QNetworkRequest request(stripSourceUrl());
    m_currentReply = m_networkManager->get(request);
    connect(m_currentReply, SIGNAL(finished()), this, SLOT(parse()));
}

void Comic::parse()
{
    QByteArray data = m_currentReply->readAll();
    QUrl stripUrl = extractStripUrl(data);
    setCurrentStripUrl(stripUrl);
    emit currentStripUrlFetched();
}
