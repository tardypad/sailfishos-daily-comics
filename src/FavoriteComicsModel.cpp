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
    connect(settings, SIGNAL(favoritesChanged()), this, SIGNAL(favoritesChanged()));
}

QStringList FavoriteComicsModel::idLoadList()
{
    return dbResource->favoriteIds();
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
