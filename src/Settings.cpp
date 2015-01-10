/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Settings.h"

#include <QDebug>

Settings* Settings::m_instance = NULL;

const QString Settings::_favoritesField = QString("favorites");

Settings::Settings(QObject *parent) :
    QObject(parent)
{
    m_settings = new QSettings(this);
}

Settings* Settings::instance()
{
    if (!m_instance) {
        m_instance = new Settings();
    }

    return m_instance;
}

Settings::~Settings()
{
    delete m_settings;
}

QStringList Settings::favoriteIds()
{
    if (!m_settings->contains(_favoritesField)) {
        return QStringList();
    }

    return value(_favoritesField).toStringList();
}

void Settings::saveFavoriteIds(QStringList favoriteIds)
{
    setValue(_favoritesField, favoriteIds);
    emit favoritesChanged();
}

QVariant Settings::value(const QString &key)
{
    return m_settings->value(key);
}

void Settings::setValue(const QString &key, const QVariant &value)
{
    m_settings->setValue(key, value);
}
