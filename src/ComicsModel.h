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
class ComicFactory;
class ComicDatabaseResource;
class Settings;

class ComicsModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(int favoritesCount READ favoritesCount NOTIFY favoritesCountChanged)
    Q_PROPERTY(int newCount READ newCount NOTIFY newCountChanged)
    Q_PROPERTY(int fetchedCount READ fetchedCount NOTIFY fetchedCountChanged)
    Q_ENUMS(Roles)

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        ColorRole,
        AuthorsRole,
        HomepageRole,
        CountryRole,
        LanguageRole,
        StartDateRole,
        EndDateRole,
        ImageRole,
        FavoriteRole,
        NewStripRole,
        ErrorRole,
        FetchingRole
    };

public:
    explicit ComicsModel(QObject *parent = 0);
    ~ComicsModel();
    virtual QHash<int,QByteArray> roleNames() const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Q_INVOKABLE void setFavorite(int row, bool favorite);
    Q_INVOKABLE void read(int row);
    Q_INVOKABLE void favoriteAll(bool favorite = true);
    Q_INVOKABLE void unfavoriteAll();
    Q_INVOKABLE void saveAll();
    Q_INVOKABLE Comic *comicAt(int row);

    int count() const;
    int favoritesCount() const;
    int newCount() const;
    int fetchedCount() const;

public slots:
    Q_INVOKABLE virtual void loadAll();
    Q_INVOKABLE void fetchAll();

protected:
    void clear();
    void initComicConnections();
    void emitDataChanged(int row, Roles role);

protected slots:
    void emitNewStripChanged(Comic* comic);
    void emitErrorChanged(Comic* comic);
    void emitFetchingChanged(Comic* comic);

signals:
    void countChanged();
    void favoritesCountChanged();
    void newCountChanged();
    void fetchedCountChanged();

protected:
    QList<Comic*> m_list;
    ComicFactory* factory;
    ComicDatabaseResource* dbResource;
    Settings* settings;
};

#endif // COMICSMODEL_H
