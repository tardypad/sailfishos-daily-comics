/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicsModel.h"

#include <QDebug>

#include "Comic.h"
#include "ComicFactory.h"

ComicsModel::ComicsModel(QObject *parent) :
    QAbstractListModel(parent),
    m_list(QList<Comic*>())
{
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
    roleNames[SelectedRole] = "selected";

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
    case SelectedRole:
        return m_list.at(index.row())->selected();
    }

    return QVariant();
}

void ComicsModel::loadAll(QStringList favoriteIds)
{
    beginInsertRows(QModelIndex(), 0, 5);
    m_list.append(ComicFactory::create("calvinandhobbes"));
    m_list.append(ComicFactory::create("dilbert"));
    m_list.append(ComicFactory::create("garfield"));
    m_list.append(ComicFactory::create("lechat"));
    m_list.append(ComicFactory::create("peanuts"));
    m_list.append(ComicFactory::create("xkcd"));

    if (!favoriteIds.empty()) {
        for (int i = 0; i < m_list.size(); ++i) {
            if (favoriteIds.contains(m_list.at(i)->id()))
                m_list.at(i)->setSelected(true);
        }
    }

    endInsertRows();
}

void ComicsModel::setSelected(int row, bool selected)
{
    m_list.at(row)->setSelected(selected);
    emit dataChanged(this->index(row), this->index(row));
}

QStringList ComicsModel::selected()
{
    QStringList selectedList;

    for(int row = 0; row < m_list.size(); ++row) {
      if (m_list.at(row)->selected())
          selectedList.append(m_list.at(row)->id());
    }

    return selectedList;
}
