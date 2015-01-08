/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicsModel.h"

#include "Comic.h"
#include "ComicFactory.h"

ComicsModel::ComicsModel(QObject *parent) :
    QAbstractListModel(parent),
    m_list(QList<Comic*>())
{
    load();
}

ComicsModel::~ComicsModel()
{
    beginResetModel();
    qDeleteAll(m_list);
    m_list.clear();
    endResetModel();
}

QHash<int, QByteArray> ComicsModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;
    roleNames[IdRole] = "id";
    roleNames[NameRole] = "name";
    roleNames[AuthorRole] = "author";
    roleNames[HomepageRole] = "homepage";
    roleNames[ImageRole] = "image";

    return roleNames;
}

int ComicsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_list.size();
}

QVariant ComicsModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= m_list.size())
        return QVariant();

    switch(role) {
    case IdRole:
        return m_list.at(index.row())->id();
    case NameRole:
        return m_list.at(index.row())->name();
    case AuthorRole:
        return m_list.at(index.row())->author();
    case HomepageRole:
        return m_list.at(index.row())->homepage();
    case ImageRole:
        return m_list.at(index.row())->currentStripUrl();
    }

    return QVariant();
}

void ComicsModel::load()
{
    beginInsertRows(QModelIndex(), 0, 5);
    m_list.append(ComicFactory::create("calvinandhobbes"));
    m_list.append(ComicFactory::create("dilbert"));
    m_list.append(ComicFactory::create("garfield"));
    m_list.append(ComicFactory::create("lechat"));
    m_list.append(ComicFactory::create("peanuts"));
    m_list.append(ComicFactory::create("xkcd"));
    endInsertRows();
}
