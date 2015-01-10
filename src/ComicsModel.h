/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMICSMODEL_H
#define COMICSMODEL_H

#include <QAbstractListModel>

class Comic;

class ComicsModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        AuthorRole,
        HomepageRole,
        ImageRole,
        SelectedRole
    };

public:
    explicit ComicsModel(QObject *parent = 0);
    ~ComicsModel();
    virtual QHash<int,QByteArray> roleNames() const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Q_INVOKABLE void loadAll(QStringList favoriteIds = QStringList());
    Q_INVOKABLE void setSelected(int row, bool selected);
    Q_INVOKABLE QStringList selected();

private:
    QList<Comic*> m_list;
};

#endif // COMICSMODEL_H
