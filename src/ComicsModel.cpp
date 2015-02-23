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
    roleNames[AuthorRole] = "author";
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
    case AuthorRole:
        return m_list.at(index.row())->author();
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
        return m_list.at(index.row())->currentStripUrl();
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

    QStringList comicsList = settings->fullComicsList();

    Comic *comic;

    beginInsertRows(QModelIndex(), 0, comicsList.count() - 1);

    for (int i = 0; i < comicsList.size(); ++i) {
        comic = ComicFactory::create(comicsList.at(i), this);
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
        m_list.at(row)->fetchCurrentStripUrl();
    }
}

void ComicsModel::setFavorite(int row, bool favorite)
{
    m_list.at(row)->setFavorite(favorite);
    emitDataChanged(row, FavoriteRole);
    emit favoritesCountChanged();
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

int ComicsModel::count() const
{
    return rowCount();
}

int ComicsModel::favoritesCount() const
{
    int favoritesCount = 0;

    for(int row = 0; row < m_list.size(); ++row) {
      if (m_list.at(row)->favorite())
          favoritesCount++;
    }

    return favoritesCount;
}

int ComicsModel::newCount() const
{
    int newCount = 0;

    for(int row = 0; row < m_list.size(); ++row) {
      if (m_list.at(row)->newStrip())
          newCount++;
    }

    return newCount;
}

int ComicsModel::fetchedCount() const
{
    int fetchedCount = 0;

    for(int row = 0; row < m_list.size(); ++row) {
      if (!m_list.at(row)->fetching())
          fetchedCount++;
    }

    return fetchedCount;
}
