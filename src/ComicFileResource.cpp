/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicFileResource.h"

#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QSqlQuery>

#include "Comic.h"

const QString ComicFileResource::_comicsDirName = "comics";

ComicFileResource* ComicFileResource::m_instance = NULL;

ComicFileResource::ComicFileResource(QObject *parent) :
    QObject(parent),
    m_dirPath("")
{
}

ComicFileResource* ComicFileResource::instance()
{
    if (!m_instance) {
        m_instance = new ComicFileResource();
        m_instance->checkCreateStructure();
    }

    return m_instance;
}

QString ComicFileResource::filePath(QString id)
{
    return dirPath().append(QDir::separator()).append(id);
}

bool ComicFileResource::isDownloaded(QString id)
{
    return QFile::exists(filePath(id));
}

bool ComicFileResource::save(QString id, QByteArray data)
{
    QFile* file = new QFile();
    file->setFileName(filePath(id));

    bool openResult = file->open(QIODevice::WriteOnly);

    if (!openResult)
        return false;

    qint64 writeResult = file->write(data);

    file->close();
    file->deleteLater();

    return writeResult > 0;
}

QString ComicFileResource::dirPath()
{
    if (m_dirPath.isEmpty()) {
        m_dirPath = QStandardPaths::writableLocation(QStandardPaths::DataLocation)
                    .append(QDir::separator()).append(_comicsDirName);
    }
    return m_dirPath;
}

void ComicFileResource::checkCreateStructure()
{
    QDir dir = QDir(dirPath());

    if (!dir.exists())
        dir.mkpath(dirPath());
}
