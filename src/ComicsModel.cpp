/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicsModel.h"

#include <QDebug>
#include <QDate>
#include <QColor>

#include "Comic.h"
#include "ComicFactory.h"
#include "ComicDatabaseResource.h"
#include "Settings.h"

ComicsModel::ComicsModel(QObject *parent) :
    QAbstractListModel(parent),
    m_list(QList<Comic*>())
{
    dbResource = ComicDatabaseResource::instance();
    factory    = ComicFactory::instance();
    settings   = Settings::instance();

    connect(this, SIGNAL(modelReset()), this, SIGNAL(countChanged()));
    connect(this, SIGNAL(modelReset()), this, SIGNAL(favoritesCountChanged()));
    connect(this, SIGNAL(modelReset()), this, SIGNAL(newCountChanged()));
    connect(this, SIGNAL(modelReset()), this, SIGNAL(fetchedCountChanged()));
}

ComicsModel::~ComicsModel()
{
    clear();
}

void ComicsModel::clear()
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
    roleNames[ColorRole] = "idColor";
    roleNames[AuthorsRole] = "authors";
    roleNames[HomepageRole] = "homepage";
    roleNames[CountryRole] = "country";
    roleNames[LanguageRole] = "language";
    roleNames[StartDateRole] = "startDate";
    roleNames[EndDateRole] = "endDate";
    roleNames[ImageRole] = "image";
    roleNames[FavoriteRole] = "favorite";
    roleNames[NewStripRole] = "newStrip";
    roleNames[ErrorRole] = "error";
    roleNames[FetchingRole] = "fetching";

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
    case ColorRole:
        return m_list.at(index.row())->color();
    case AuthorsRole:
        return m_list.at(index.row())->authors();
    case HomepageRole:
        return m_list.at(index.row())->homepage();
    case CountryRole:
        return m_list.at(index.row())->country();
    case LanguageRole:
        return m_list.at(index.row())->language();
    case StartDateRole:
        return m_list.at(index.row())->startDate();
    case EndDateRole:
        return m_list.at(index.row())->endDate();
    case ImageRole:
        return m_list.at(index.row())->stripUrl();
    case FavoriteRole:
        return m_list.at(index.row())->favorite();
    case NewStripRole:
        return m_list.at(index.row())->newStrip();
    case ErrorRole:
        return m_list.at(index.row())->error();
    case FetchingRole:
        return m_list.at(index.row())->fetching();
    }

    return QVariant();
}

void ComicsModel::loadAll()
{
    clear();

    QStringList comicsList = factory->fullList();

    Comic *comic;

    beginInsertRows(QModelIndex(), 0, comicsList.count() - 1);

    for (int i = 0; i < comicsList.size(); ++i) {
        comic = factory->create(comicsList.at(i), this);
        comic->load();
        m_list.append(comic);
    }

    endInsertRows();

    emit countChanged();
    emit favoritesCountChanged();
}

void ComicsModel::initComicConnections()
{
    for(int row = 0; row < m_list.size(); ++row) {
        connect(m_list.at(row), SIGNAL(newStripChanged(Comic*)), this, SLOT(emitNewStripChanged(Comic*)));
        connect(m_list.at(row), SIGNAL(errorChanged(Comic*)), this, SLOT(emitErrorChanged(Comic*)));
        connect(m_list.at(row), SIGNAL(fetchingChanged(Comic*)), this, SLOT(emitFetchingChanged(Comic*)));
    }
}

void ComicsModel::emitDataChanged(int row, ComicsModel::Roles role)
{
    QVector<int> roleVector;
    roleVector << role;
    emit dataChanged(index(row), index(row), roleVector);
}

void ComicsModel::emitNewStripChanged(Comic *comic)
{
    for(int row = 0; row < m_list.size(); ++row) {
        if (m_list.at(row) == comic) {
            emitDataChanged(row, NewStripRole);
            emit newCountChanged();
            return;
        }
    }
}

void ComicsModel::emitErrorChanged(Comic *comic)
{
    for(int row = 0; row < m_list.size(); ++row) {
        if (m_list.at(row) == comic) {
            emitDataChanged(row, ErrorRole);
            emit errorCountChanged();
            return;
        }
    }
}

void ComicsModel::emitFetchingChanged(Comic *comic)
{
    for(int row = 0; row < m_list.size(); ++row) {
        if (m_list.at(row) == comic) {
            emitDataChanged(row, FetchingRole);
            emit fetchedCountChanged();
            return;
        }
    }
}

void ComicsModel::fetchAll()
{
    for(int row = 0; row < m_list.size(); ++row) {
        m_list.at(row)->fetchStripUrl();
    }
}

void ComicsModel::setFavorite(int row, bool favorite)
{
    m_list.at(row)->setFavorite(favorite);
    emitDataChanged(row, FavoriteRole);
    emit favoritesCountChanged();
}

void ComicsModel::read(int row)
{
    m_list.at(row)->read();
}

void ComicsModel::favoriteAll(bool favorite)
{
    for(int row = 0; row < m_list.size(); ++row) {
        setFavorite(row, favorite);
    }
}

void ComicsModel::unfavoriteAll()
{
    favoriteAll(false);
}

void ComicsModel::saveAll()
{
    for(int row = 0; row < m_list.size(); ++row) {
        m_list.at(row)->save();
    }
}

Comic *ComicsModel::comicAt(int row)
{
    if (row < 0 || row >= m_list.size())
        return NULL;

    return m_list.at(row);
}

QStringList ComicsModel::errorComicNames()
{
    QStringList(errorComicNames);

    for(int row = 0; row < m_list.size(); ++row) {
      if (m_list.at(row)->error())
          errorComicNames << m_list.at(row)->name();
    }

    return errorComicNames;
}

int ComicsModel::count() const
{
    return rowCount();
}

int ComicsModel::roleCount(ComicsModel::Roles role, QVariant value) const
{
    int count = 0;

    for (int row = 0; row < m_list.size(); ++row) {
      if (data(index(row), role) == value)
          count++;
    }

    return count;
}

int ComicsModel::favoritesCount() const
{
    return roleCount(FavoriteRole, true);
}

int ComicsModel::newCount() const
{
    return roleCount(NewStripRole, true);
}

int ComicsModel::fetchedCount() const
{
    return roleCount(FetchingRole, false);
}

int ComicsModel::errorCount() const
{
    return roleCount(ErrorRole, true);
}
