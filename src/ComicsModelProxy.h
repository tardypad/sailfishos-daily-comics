/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMICSMODELPROXY_H
#define COMICSMODELPROXY_H

#include <QSortFilterProxyModel>

#include "ComicsModel.h"

class ComicsModelProxy : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(ComicsModel* comicsModel READ comicsModel WRITE setComicsModel NOTIFY comicsModelChanged)
    Q_ENUMS(ComicsModel::Roles)

public:
    explicit ComicsModelProxy(QObject *parent = 0);
    virtual bool filterAcceptsRow (int source_row, const QModelIndex& source_parent) const;

    ComicsModel* comicsModel() const { return m_comicsModel; }
    void setComicsModel(ComicsModel* comicsModel);

signals:
    void comicsModelChanged();

private:
    ComicsModel* m_comicsModel;
};

#endif // COMICSMODELPROXY_H
