/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FavoriteComicsModel.h"

#include <QDebug>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

#include "ComicFactory.h"
#include "Comic.h"
#include "ComicDatabaseResource.h"
#include "ComicsInfoUpdater.h"
#include "Settings.h"

FavoriteComicsModel::FavoriteComicsModel(QObject *parent) :
    ComicsModel(parent),
    m_comicsInfoUpdater(new ComicsInfoUpdater(this))
{
    connect(settings, &Settings::favoritesChanged, this, &FavoriteComicsModel::favoritesChanged);

    connect(m_comicsInfoUpdater.data(), &ComicsInfoUpdater::gotUpdateInfo,
            this, &FavoriteComicsModel::handleGotUpdateInfo);
}

QStringList FavoriteComicsModel::idLoadList()
{
    QStringList fullList = factory->fullList();
    QStringList favoritesList = dbResource->favoriteIds();

    QStringList loadList;
    QString comicId;

    for (int i = 0; i < favoritesList.size(); ++i) {
        comicId = favoritesList.at(i);
        if (fullList.contains(comicId))
            loadList << comicId;
    }

    return loadList;
}

void FavoriteComicsModel::updateComics(const QJsonDocument& updateInfo)
{
    QJsonObject object = updateInfo.object();
    if (!object.contains("plugins") || !object["plugins"].isArray())
    {
        return;
    }

    QJsonArray array = object["plugins"].toArray();
    for (const QJsonValue& value : array)
    {
        if (!value.isObject())
        {
            continue;
        }

        QJsonObject update = value.toObject();
        if (!update.contains("id"))
        {
            continue;
        }
        const QString id = update["id"].toString();
        auto it = std::find_if(m_list.begin(), m_list.end(), [id](decltype(m_list.front()) item)
            { return item->id() == id; });
        if (it == m_list.end())
        {
            continue;
        }
        ComicInfo info = (*it)->getInfo();
        if (update.contains("stripSource") && update["stripSource"].isString())
        {
            info.stripSourceUrl = QUrl(update["stripSource"].toString());
        }
        (*it)->setInfo(info);

        if (update.contains("extractJson") && update["extractJson"].isString())
        {
            (*it)->setExtractScript(update["extractJson"].toString());
        }
    }
}

void FavoriteComicsModel::removeFavorite(int row)
{
    Comic* comic = comicAt(row);

    if (comic == NULL)
        return;

    comic->setFavorite(false);
    comic->save();

    beginRemoveRows(QModelIndex(), row, row);
    m_list.removeAt(row);
    endRemoveRows();
}

void FavoriteComicsModel::fetchAll()
{
    m_comicsInfoUpdater->startUpdate();
}

void FavoriteComicsModel::handleGotUpdateInfo(const QJsonDocument& updateInfo)
{
    if (!updateInfo.isNull())
    {
        updateComics(updateInfo);
    }
    ComicsModel::fetchAll();
}
