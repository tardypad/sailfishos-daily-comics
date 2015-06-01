/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMICFILERESOURCE_H
#define COMICFILERESOURCE_H

#include <QObject>
#include <QSqlDatabase>

class Comic;

class ComicFileResource : public QObject
{
    Q_OBJECT

    static const QString _comicsDirName;

public:
    static ComicFileResource* instance();
    QString filePath(QString id);
    bool save(QString id, QByteArray data);

private:
    explicit ComicFileResource(QObject *parent = 0);
    QString dirPath();
    void checkCreateStructure();

private:
    static ComicFileResource* m_instance;
    QString m_dirPath;
};

#endif // COMICFILERESOURCE_H
