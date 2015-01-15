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
class Settings;

class ComicsModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(int favoritesCount READ favoritesCount NOTIFY favoritesCountChanged)

public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        ColorRole,
        AuthorRole,
        HomepageRole,
        CountryRole,
        LanguageRole,
        StartDateRole,
        EndDateRole,
        ImageRole,
        FavoriteRole,
        NewStripRole,
        ErrorRole
    };

public:
    explicit ComicsModel(QObject *parent = 0);
    ~ComicsModel();
    virtual QHash<int,QByteArray> roleNames() const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Q_INVOKABLE void setFavorite(int row, bool favorite);
    Q_INVOKABLE QStringList favoriteIds();
    Q_INVOKABLE void favoriteAll(bool favorite = true);
    Q_INVOKABLE void unfavoriteAll();

    int count() const;
    int favoritesCount() const;

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

signals:
    void countChanged();
    void favoritesCountChanged();

protected:
    QList<Comic*> m_list;
    Settings *m_settings;
};

#endif // COMICSMODEL_H
