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
    Q_PROPERTY(QString country READ country NOTIFY countryChanged)
    Q_PROPERTY(QString language READ language NOTIFY languageChanged)
    Q_PROPERTY(QDate startDate READ startDate NOTIFY startDateChanged)
    Q_PROPERTY(QDate endDate READ endDate NOTIFY endDateChanged)
    Q_PROPERTY(QUrl stripPath READ stripPath NOTIFY stripPathChanged)
    Q_PROPERTY(bool error READ error NOTIFY errorChanged)

public:
    explicit ComicProxy(QObject *parent = 0);

    QString id() const;
    QString name() const;
    QStringList authors() const;
    QUrl homepage() const;
    QString country() const;
    QString language() const;
    QDate startDate() const;
    QDate endDate() const;
    QUrl stripPath();
    bool error();

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
    void countryChanged();
    void languageChanged();
    void startDateChanged();
    void endDateChanged();
    void stripPathChanged();
    void errorChanged();

    void fetchStarted();
    void fetchFinished();
    void networkError();
    void parsingError();
    void savingError();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);

private:
    Comic* m_comic;
};

#endif // COMICPROXY_H
