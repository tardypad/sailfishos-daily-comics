/**
 * Copyright (c) 2018-2019 Oleg Linkin <maledictusdemagog@gmail.com>
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#pragma once

#include <QJsonDocument>
#include <QObject>
#include <QSharedPointer>

class QNetworkAccessManager;

class ComicsInfoUpdater : public QObject
{
    Q_OBJECT

    QSharedPointer<QNetworkAccessManager> m_NAM;

public:
    explicit ComicsInfoUpdater(QObject *parent = nullptr);

public slots:
    void startUpdate();

private slots:
    void updateDownloaded();

signals:
    void gotUpdateInfo(const QJsonDocument& updateInfo);
};
