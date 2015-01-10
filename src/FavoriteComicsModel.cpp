/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FavoriteComicsModel.h"

#include <QDebug>

#include "Settings.h"
#include "ComicFactory.h"

FavoriteComicsModel::FavoriteComicsModel(QObject *parent) :
    ComicsModel(parent)
{
    connect(m_settings, SIGNAL(favoritesChanged()), this, SLOT(loadAll()));
}

void FavoriteComicsModel::loadAll()
{
    clear();

    QStringList favoriteIds = m_settings->favoriteIds();

    beginInsertRows(QModelIndex(), 0, favoriteIds.size() - 1);

    for (int i = 0; i < favoriteIds.size(); ++i) {
        m_list.append(ComicFactory::create(favoriteIds.at(i)));
    }

    endInsertRows();

    emit countChanged();
}
