/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicStripFileResource.h"

#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QSqlQuery>

#include "Comic.h"

const QString ComicStripFileResource::_comicsDirName = "comics";

ComicStripFileResource* ComicStripFileResource::m_instance = NULL;

ComicStripFileResource::ComicStripFileResource(QObject *parent) :
    QObject(parent),
    m_dirPath("")
{
}

ComicStripFileResource* ComicStripFileResource::instance()
{
    if (!m_instance) {
        m_instance = new ComicStripFileResource();
        m_instance->checkCreateStructure();
    }

    return m_instance;
}

QString ComicStripFileResource::path(QString id)
{
    return dirPath().append(QDir::separator()).append(id);
}

bool ComicStripFileResource::isDownloaded(QString id)
{
    return QFile::exists(path(id));
}

bool ComicStripFileResource::save(QString id, QByteArray data)
{
    QFile* file = new QFile();
    file->setFileName(path(id));

    bool openResult = file->open(QIODevice::WriteOnly);

    if (!openResult)
        return false;

    qint64 writeResult = file->write(data);

    file->close();
    file->deleteLater();

    return writeResult > 0;
}

QString ComicStripFileResource::dirPath()
{
    if (m_dirPath.isEmpty()) {
        m_dirPath = QStandardPaths::writableLocation(QStandardPaths::DataLocation)
                    .append(QDir::separator()).append(_comicsDirName);
    }
    return m_dirPath;
}

void ComicStripFileResource::checkCreateStructure()
{
    QDir dir = QDir(dirPath());

    if (!dir.exists())
        dir.mkpath(dirPath());
}
