/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>

#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT

    static const QString _favoritesField;

public:
    explicit Settings(QObject *parent = 0);
    ~Settings();
    Q_INVOKABLE QStringList favoriteIds();
    Q_INVOKABLE void saveFavoriteIds(QStringList favoriteIds);

protected:
    QVariant value(const QString &key);
    void setValue(const QString &key, const QVariant &value);

private:
     QSettings* m_settings;
};

#endif // SETTINGS_H
