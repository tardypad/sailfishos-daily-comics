/**
 * Copyright (c) 2016 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMICINFOFILERESOURCE_H
#define COMICINFOFILERESOURCE_H

#include <QObject>

#include "Comic.h"

class ComicInfoFileResource : public QObject
{
    Q_OBJECT

    static const QString _pluginsFolderPath;
    static const QString _infoFileName;

public:
    static ComicInfoFileResource* instance();
    bool load(Comic* comic);

private:
    explicit ComicInfoFileResource(QObject *parent = 0);
    QString path(QString id);
    ComicInfo parse(QByteArray infoData);

private:
    static ComicInfoFileResource* m_instance;
};

#endif // COMICINFOFILERESOURCE_H
