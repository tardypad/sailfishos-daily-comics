/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FavoriteComicsModel.h"

#include <QDebug>

#include "ComicFactory.h"
#include "Comic.h"
#include "ComicDatabaseResource.h"
#include "Settings.h"

FavoriteComicsModel::FavoriteComicsModel(QObject *parent) :
    ComicsModel(parent)
{
    connect(Settings::instance(), SIGNAL(favoritesChanged()), this, SIGNAL(favoritesChanged()));
}

void FavoriteComicsModel::loadAll()
{
    clear();

    QStringList favoriteIds = dbResource->favoriteIds();

    Comic *comic;

    beginInsertRows(QModelIndex(), 0, favoriteIds.size() - 1);

    for (int i = 0; i < favoriteIds.size(); ++i) {
        comic = ComicFactory::create(favoriteIds.at(i), this);
        comic->load();
        m_list.append(comic);
    }

    initComicConnections();

    endInsertRows();

    emit countChanged();
}
