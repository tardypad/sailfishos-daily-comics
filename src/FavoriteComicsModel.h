/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef FAVORITECOMICSMODEL_H
#define FAVORITECOMICSMODEL_H

#include "ComicsModel.h"

class FavoriteComicsModel : public ComicsModel
{
    Q_OBJECT
public:
    explicit FavoriteComicsModel(QObject *parent = 0);

public slots:
    Q_INVOKABLE virtual void loadAll();

signals:
    void favoritesChanged();
};

#endif // FAVORITECOMICSMODEL_H
