/**
 * Copyright (c) 2016 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicInfoFileResource.h"

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QColor>
#include <QLocale>

const QString ComicInfoFileResource::_pluginsFolderPath = QString(PLUGINS_FOLDER_PATH);
const QString ComicInfoFileResource::_infoFileName = "info.json";

ComicInfoFileResource* ComicInfoFileResource::m_instance = NULL;

ComicInfoFileResource::ComicInfoFileResource(QObject *parent) :
    QObject(parent)
{
}

ComicInfoFileResource* ComicInfoFileResource::instance()
{
    if (!m_instance) {
        m_instance = new ComicInfoFileResource();
    }

    return m_instance;
}

bool ComicInfoFileResource::load(Comic *comic)
{
    QString id = comic->id();

    QFile* infoFile = new QFile();
    infoFile->setFileName(path(id));

    if (!infoFile->open(QIODevice::ReadOnly))
        return false;

    ComicInfo info = parse(infoFile->readAll());
    info.id = id;
    comic->setInfo(info);

    infoFile->close();
    infoFile->deleteLater();

    return true;
}

QString ComicInfoFileResource::path(QString id)
{
    return QDir(_pluginsFolderPath).path()
            .append(QDir::separator()).append(id)
            .append(QDir::separator()).append(_infoFileName);
}

ComicInfo ComicInfoFileResource::parse(QByteArray infoData)
{
    ComicInfo info;

    QJsonDocument jsonDoc = QJsonDocument::fromJson(infoData);
    QJsonObject infoJson = jsonDoc.object();

    info.name           = infoJson.value("name").toString();
    info.homepage       = infoJson.value("homepage").toString();
    info.stripSourceUrl = infoJson.value("stripSource").toString();
    info.color          = QColor('#' + infoJson.value("color").toString());
    info.language       = QLocale(infoJson.value("language").toString()).language();

    foreach (const QJsonValue & author, infoJson.value("authors").toArray())
        info.authors << author.toString();

    return info;
}
