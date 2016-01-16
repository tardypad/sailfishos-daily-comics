/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMICDATABASERESOURCE_H
#define COMICDATABASERESOURCE_H

#include <QObject>
#include <QSqlDatabase>

class Comic;

class ComicDatabaseResource : public QObject
{
    Q_OBJECT

    static const QString _databaseName;
    static const QString _comicsTableName;

public:
    static ComicDatabaseResource* instance();
    bool openDb();
    bool load(Comic* comic);
    bool save(Comic* comic);
    QStringList favoriteIds();
    bool saveFavorites(QStringList favoriteIds);

private:
    explicit ComicDatabaseResource(QObject *parent = 0);
    QString dbDirPath();
    QString dbFilePath();
    void checkStructure();
    bool createStructure();
    bool createDbFile();

private:
    static ComicDatabaseResource* m_instance;
    QSqlDatabase db;
    QString m_dbDirPath;
    QString m_dbFilePath;
};

#endif // COMICDATABASERESOURCE_H
