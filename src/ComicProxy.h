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
#include <QDate>
#include <QLocale>

class Comic;

class ComicProxy : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString id READ id NOTIFY idChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QStringList authors READ authors NOTIFY authorsChanged)
    Q_PROPERTY(QUrl homepage READ homepage NOTIFY homepageChanged)
    Q_PROPERTY(QString language READ language NOTIFY languageChanged)
    Q_PROPERTY(QString coverPath READ coverPath NOTIFY coverPathChanged)
    Q_PROPERTY(QString examplePath READ examplePath NOTIFY examplePathChanged)
    Q_PROPERTY(QUrl stripImagePath READ stripImagePath NOTIFY stripImagePathChanged)
    Q_PROPERTY(QUrl stripImageUrl READ stripImageUrl NOTIFY stripImageUrlChanged)
    Q_PROPERTY(bool error READ error NOTIFY errorChanged)
    Q_PROPERTY(bool animated READ animated NOTIFY animatedChanged)

    Q_PROPERTY(Comic* comic READ comic WRITE setComic NOTIFY comicChanged)

public:
    explicit ComicProxy(QObject *parent = 0);

    QString id() const;
    QString name() const;
    QStringList authors() const;
    QUrl homepage() const;
    QString language() const;
    QUrl stripImagePath() const;
    QUrl stripImageUrl() const;
    QString coverPath() const;
    QString examplePath() const;
    bool error() const;
    bool animated() const;
    Comic* comic() const;


    Q_INVOKABLE void setComic(Comic* comic);

    Q_INVOKABLE void fetch();
    Q_INVOKABLE void abortFetching();
    Q_INVOKABLE void read();
    Q_INVOKABLE void setError();

signals:
    void idChanged();
    void nameChanged();
    void authorsChanged();
    void homepageChanged();
    void languageChanged();
    void stripImagePathChanged();
    void stripImageUrlChanged();
    void coverPathChanged();
    void examplePathChanged();
    void errorChanged();
    void animatedChanged();
    void comicChanged();

    void fetchStarted();
    void fetchSucceeded();
    void networkError();
    void parsingError();
    void savingError();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);

private:
    Comic* m_comic;
};

#endif // COMICPROXY_H
