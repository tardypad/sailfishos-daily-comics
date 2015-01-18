/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicDatabaseResource.h"

#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QSqlQuery>

#include "Comic.h"

const QString ComicDatabaseResource::_databaseName = "dailycomics.sqlite";
const QString ComicDatabaseResource::_comicsTableName = "comics";

ComicDatabaseResource* ComicDatabaseResource::m_instance = NULL;

ComicDatabaseResource::ComicDatabaseResource(QObject *parent) :
    QObject(parent),
    m_dbDirPath(""),
    m_dFilePath("")
{
    db = QSqlDatabase::addDatabase("QSQLITE");

    if (!db.isOpen())
        openDb();
    checkStructure();
}

ComicDatabaseResource* ComicDatabaseResource::instance()
{
    if (!m_instance) {
        m_instance = new ComicDatabaseResource();
    }

    return m_instance;
}

bool ComicDatabaseResource::openDb()
{
    if (!QFile::exists(dbFilePath()) && !createDbFile())
        return false;
    db.setDatabaseName(dbFilePath());

    return db.open();
}

bool ComicDatabaseResource::load(Comic *comic)
{
    QSqlQuery query("SELECT time, url FROM " + _comicsTableName + " WHERE id='" + comic->id() + "'");

    query.first();

    QDateTime time = query.value(0).toDateTime();
    QUrl url = query.value(1).toUrl();

    comic->setLastStripFetchTime(time);
    comic->setLastStripUrl(url);

    return true;
}

bool ComicDatabaseResource::save(Comic *comic)
{
    QSqlQuery query(db);
    query.prepare("REPLACE INTO " + _comicsTableName + "(id, time, url) \n"
                  "VALUES (:id, :time, :url)");

    query.bindValue(":time",  comic->lastStripFetchTime());
    query.bindValue(":url",   comic->lastStripUrl());
    query.bindValue(":id",    comic->id());

    return query.exec();
}

QString ComicDatabaseResource::dbDirPath()
{
    if (m_dbDirPath.isEmpty()) {
        m_dbDirPath = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    }
    return m_dbDirPath;
}

QString ComicDatabaseResource::dbFilePath()
{
    if (m_dFilePath.isEmpty()) {
        m_dFilePath = dbDirPath().append(QDir::separator()).append(_databaseName);
    }
    return m_dFilePath;
}

bool ComicDatabaseResource::createDbFile()
{
    QDir dbDir;
    QFile dbFile(dbFilePath());

    return dbDir.mkpath(dbDirPath()) && dbFile.open(QIODevice::ReadWrite);
}

void ComicDatabaseResource::checkStructure()
{
    if (!db.isOpen())
        return;

    if (!db.tables().contains(_comicsTableName)) {
        createStructure();
    }
}

bool ComicDatabaseResource::createStructure()
{
    if (!db.isOpen())
        return false;

    QSqlQuery query("CREATE TABLE " + _comicsTableName + " (\n"
                    "id   VARCHAR(50)  PRIMARY KEY,  -- comic id \n"
                    "time DATETIME     DEFAULT NULL, -- last successful fetch time \n"
                    "url  VARCHAR(300) DEFAULT NULL  -- last retrieved image url \n"
                    ")", db);

    return query.exec();
}

