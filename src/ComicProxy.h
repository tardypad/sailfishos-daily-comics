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
    Q_PROPERTY(QString author READ author NOTIFY authorChanged)
    Q_PROPERTY(QUrl homepage READ homepage NOTIFY homepageChanged)
    Q_PROPERTY(QString country READ country NOTIFY countryChanged)
    Q_PROPERTY(QString language READ language NOTIFY languageChanged)
    Q_PROPERTY(QDate startDate READ startDate NOTIFY startDateChanged)
    Q_PROPERTY(QDate endDate READ endDate NOTIFY endDateChanged)
    Q_PROPERTY(QUrl stripUrl READ stripUrl NOTIFY stripUrlChanged)

public:
    explicit ComicProxy(QObject *parent = 0);

    QString id() const;
    QString name() const;
    QString author() const;
    QUrl homepage() const;
    QString country() const;
    QString language() const;
    QDate startDate() const;
    QDate endDate() const;
    QUrl stripUrl();

    Q_INVOKABLE void setComic(Comic* comic);

    Q_INVOKABLE void fetch();
    Q_INVOKABLE void abortFetching();
    Q_INVOKABLE void read();

signals:
    void idChanged();
    void nameChanged();
    void authorChanged();
    void homepageChanged();
    void countryChanged();
    void languageChanged();
    void startDateChanged();
    void endDateChanged();
    void stripUrlChanged();

    void fetchStarted();
    void dataParsed();
    void networkError();
    void parsingError();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);

private:
    Comic* m_comic;
};

#endif // COMICPROXY_H
