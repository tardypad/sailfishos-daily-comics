/**
 * Copyright (c) 2016 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef  COMICPLUGINRESOURCE_H
#define  COMICPLUGINRESOURCE_H

#include <QObject>

#include "Comic.h"

class QJSEngine;

class ComicPluginResource : public QObject
{
    Q_OBJECT

public:
    static ComicPluginResource* instance();

    void load(Comic* comic);
    QUrl extractStripImageUrl(Comic* comic, QByteArray data);

private:
    explicit ComicPluginResource(QObject *parent = 0);

    void loadInfo(Comic* comic);
    void loadCoverPath(Comic* comic);
    void loadExamplePath(Comic* comic);

    QString path(QString id, QString filename);
    ComicInfo parseInfo(QByteArray infoData);

private:
    static const QString _pluginsFolderPath;
    static const QString _infoFileName;
    static const QString _coverFilename;
    static const QString _exampleFilename;
    static const QString _extractScriptFilename;

    static QJSEngine* _jsEngine;

    static ComicPluginResource* m_instance;
};

#endif //  COMICPLUGINRESOURCE_H
