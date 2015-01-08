/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef COMICPROXY_H
#define COMICPROXY_H

#include <QObject>

#include <QUrl>

class Comic;

class ComicProxy : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString comicId READ comicId WRITE setComicId NOTIFY comicIdChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QString author READ author NOTIFY authorChanged)
    Q_PROPERTY(QUrl homepage READ homepage NOTIFY homepageChanged)
    Q_PROPERTY(QUrl currentStripUrl READ currentStripUrl NOTIFY currentStripUrlChanged)

public:
    explicit ComicProxy(QObject *parent = 0);

    QString comicId() const;
    QString name() const;
    QString author() const;
    QUrl homepage() const;
    QUrl currentStripUrl();

    void setComicId(const QString comicId);

    Q_INVOKABLE void fetchCurrentStrip();

signals:
    void comicIdChanged();
    void nameChanged();
    void authorChanged();
    void homepageChanged();
    void currentStripUrlChanged();

private:
    Comic* m_comic;
};

#endif // COMICPROXY_H
