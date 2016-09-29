/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMICSTRIPFILERESOURCE_H
#define COMICSTRIPFILERESOURCE_H

#include <QObject>
#include <QSqlDatabase>

class Comic;

class ComicStripFileResource : public QObject
{
    Q_OBJECT

    static const QString _comicsDirName;

public:
    static ComicStripFileResource* instance();
    QString path(QString id);
    bool isDownloaded(QString id);
    bool save(QString id, QByteArray data);

private:
    explicit ComicStripFileResource(QObject *parent = 0);
    QString dirPath();
    void checkCreateStructure();

private:
    static ComicStripFileResource* m_instance;
    QString m_dirPath;
};

#endif // COMICSTRIPFILERESOURCE_H
