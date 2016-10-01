/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Xkcd.h"

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>

Xkcd::Xkcd(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("xkcd");
}

QUrl Xkcd::extractStripImageUrl(QByteArray data)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(data);
    QString src = jsonDoc.object().value("img").toString();

    return QUrl(src);
}
