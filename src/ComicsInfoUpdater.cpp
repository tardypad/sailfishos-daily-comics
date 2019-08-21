/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicsInfoUpdater.h"

#include <QJsonParseError>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include "Settings.h"

ComicsInfoUpdater::ComicsInfoUpdater(QObject *parent)
: QObject(parent)
, m_NAM(new QNetworkAccessManager(this))
{
}

void ComicsInfoUpdater::startUpdate()
{
    if (!m_NAM)
    {
        return;
    }

    QNetworkRequest request(Settings::instance()->getUpdaterUrl());
    auto reply = m_NAM->get(request);
    connect(reply, &QNetworkReply::finished, this, &ComicsInfoUpdater::updateDownloaded);
}

void ComicsInfoUpdater::updateDownloaded()
{
    QJsonDocument doc;
    auto reply = qobject_cast<QNetworkReply*>(sender());
    if (!reply)
    {
        qWarning() << "Invalid reply";
        emit gotUpdateInfo(doc);
        return;
    }
    reply->deleteLater();

    if (reply->error() != QNetworkReply::NoError)
    {
        qWarning() << Q_FUNC_INFO << "There is network error: "
                << reply->error() << reply->errorString();
        emit gotUpdateInfo(doc);
        return;
    }

    QJsonParseError err;
    doc = QJsonDocument::fromJson(reply->readAll(), &err);
    if (err.error != QJsonParseError::NoError)
    {
        qWarning() << "Unable to generate json from reply";
        emit gotUpdateInfo(doc);
        return;
    }

    emit gotUpdateInfo(doc);
}
