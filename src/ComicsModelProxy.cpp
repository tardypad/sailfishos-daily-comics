/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicsModelProxy.h"

ComicsModelProxy::ComicsModelProxy(QObject *parent) :
    QSortFilterProxyModel(parent)
{
    connect(this, SIGNAL(sourceModelChanged()), this, SIGNAL(comicsModelChanged()));
}

void ComicsModelProxy::setComicsModel(ComicsModel *comicsModel)
{
    setSourceModel((QAbstractItemModel*) comicsModel);
    m_comicsModel = comicsModel;
}
