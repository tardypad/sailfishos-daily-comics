/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicsModelProxy.h"

#include <QDebug>

ComicsModelProxy::ComicsModelProxy(QObject *parent) :
    QSortFilterProxyModel(parent)
{
    setDynamicSortFilter(false);

    connect(this, &ComicsModelProxy::sourceModelChanged, this, &ComicsModelProxy::comicsModelChanged);
}

bool ComicsModelProxy::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    Q_UNUSED(source_parent);

    QModelIndex index = sourceModel()->index(source_row, 0);

    bool hasNewStrip = sourceModel()->data(index, ComicsModel::NewStripRole).toBool();
    if (filterRole() == ComicsModel::NewStripRole && !hasNewStrip)
        return false;

    return true;
}

void ComicsModelProxy::setComicsModel(ComicsModel *comicsModel)
{
    setSourceModel((QAbstractItemModel*) comicsModel);
    m_comicsModel = comicsModel;
    sort(0);
}

int ComicsModelProxy::sourceRow(int row)
{
    return mapToSource(index(row, 0)).row();
}
