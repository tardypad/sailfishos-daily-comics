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
    m_dbFilePath("")
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

ComicDatabaseResource* ComicDatabaseResource::instance()
{
    if (!m_instance) {
        m_instance = new ComicDatabaseResource();
        m_instance->openDb();
        m_instance->checkStructure();
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
    QSqlQuery query("SELECT time, url, read, favorite FROM " + _comicsTableName +  " WHERE id='" + comic->id() + "'");

    if (!query.first())
        return false;

    QDateTime time = query.value(0).toDateTime();
    QUrl url       = query.value(1).toUrl();
    bool read      = query.value(2).toBool();
    bool favorite  = query.value(3).toBool();

    comic->setFetchTime(time);
    comic->setStripImageUrl(url);
    comic->setNewStrip(!read);
    comic->setFavorite(favorite);

    return true;
}

bool ComicDatabaseResource::save(Comic *comic)
{
    QSqlQuery query(db);
    query.prepare("REPLACE INTO " + _comicsTableName + " (id, time, url, read, favorite) \n"
                  "VALUES (:id, :time, :url, :read, :favorite)");

    query.bindValue(":time",     comic->fetchTime());
    query.bindValue(":url",      comic->stripImageUrl());
    query.bindValue(":read",     !comic->newStrip());
    query.bindValue(":id",       comic->id());
    query.bindValue(":favorite", comic->favorite());

    return query.exec();
}

QStringList ComicDatabaseResource::favoriteIds()
{
    QSqlQuery query("SELECT id FROM " + _comicsTableName +  " WHERE favorite <> 0");
    QStringList favoriteIds;

    while (query.next()) {
        favoriteIds.append(query.value(0).toString());
    }

    return favoriteIds;
}

bool ComicDatabaseResource::saveFavorites(QStringList favoriteIds)
{
    QSqlQuery query(db);
    bool result;

    if (!db.transaction())
        return false;

    result = query.exec("UPDATE " + _comicsTableName + " SET favorite = 0");

    if (!result) {
        db.rollback();
        return false;
    }

    if (!favoriteIds.isEmpty())
    {
        result = query.exec("UPDATE " + _comicsTableName + " SET favorite = 1 \n"
                            "WHERE id IN (\"" + favoriteIds.join("\",\"") + "\")");

        if (!result) {
            db.rollback();
            return false;
        }

        QSqlQuery query("SELECT id FROM " + _comicsTableName +  " \n");

        while (query.next()) {
            favoriteIds.removeAll(query.value(0).toString());
        }

        if (!favoriteIds.empty()) {

            QStringList values;
            for (int i = 0; i < favoriteIds.size(); ++i) {
                values.append("('" + favoriteIds.at(i) + "', '1')");
            }

            result = query.exec("INSERT INTO " + _comicsTableName + " (id, favorite) \n"
                                "VALUES " + values.join(','));

            if (!result) {
                db.rollback();
                return false;
            }
        }
    }

    return db.commit();
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
    if (m_dbFilePath.isEmpty()) {
        m_dbFilePath = dbDirPath().append(QDir::separator()).append(_databaseName);
    }

    return m_dbFilePath;
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
                    "id       VARCHAR(50)  PRIMARY KEY,  -- comic id \n"
                    "time     DATETIME     DEFAULT NULL, -- last successful fetch time \n"
                    "url      VARCHAR(300) DEFAULT NULL, -- last retrieved image url \n"
                    "read     INTEGER(1)   DEFAULT 0,    -- 0 if not read \n"
                    "favorite INTEGER(1)   DEFAULT 0     -- 0 if not favorite \n"
                    ")", db);

    return query.exec();
}

