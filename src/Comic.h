/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMIC_H
#define COMIC_H

#include <QObject>

#include <QUrl>

class Comic : public QObject
{
    Q_OBJECT

public:
    explicit Comic(QObject *parent = 0);

    virtual QString id() const = 0;
    virtual QString name() const = 0;
    virtual QString author() const = 0;
    virtual QUrl homepage() const = 0;
    virtual QUrl extractStripUrl() = 0;

    QUrl currentStripUrl() const { return m_currentStripUrl; }

    void fetchCurrentStripUrl();

protected:
    virtual QUrl stripSourceUrl() const = 0;

    void setCurrentStripUrl(const QUrl currentStripUrl) { m_currentStripUrl = currentStripUrl; }

signals:
    void currentStripUrlFetched();

protected:
    QUrl m_currentStripUrl;
};

#endif // COMIC_H
