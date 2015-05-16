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
#include <QLocale>
#include <QDateTime>

class QNetworkAccessManager;
class QNetworkReply;
class ComicDatabaseResource;

class Comic : public QObject
{
    Q_OBJECT

public:
    explicit Comic(QObject *parent = 0);
    ~Comic();

    virtual QString id() const = 0;
    virtual QString name() const = 0;
    virtual QColor color() const = 0;
    virtual QStringList authors() const = 0;
    virtual QUrl homepage() const = 0;
    virtual QLocale::Country country() const = 0;
    virtual QLocale::Language language() const = 0;
    virtual QDate startDate() const = 0;
    virtual QDate endDate() const = 0;
    virtual QUrl extractStripUrl(QByteArray data) = 0;

    QUrl stripUrl() const { return m_stripUrl; }
    bool favorite() const { return m_favorite; }
    bool newStrip() const { return m_newStrip; }
    bool error() const { return m_error; }
    bool fetching() const { return m_fetching; }
    QDateTime fetchTime() const { return m_fetchTime; }

    void setFavorite(const bool favorite) { m_favorite = favorite; }
    void setNewStrip(const bool newStrip) { m_newStrip = newStrip; emit newStripChanged(this); }
    void setError(const bool error) { m_error = error; emit errorChanged(this);}
    void setFetching(const bool fetching) { m_fetching = fetching; emit fetchingChanged(this); }
    void setFetchTime(const QDateTime fetchTime) { m_fetchTime = fetchTime; }
    void setStripUrl(const QUrl stripUrl) { m_stripUrl = stripUrl; }

    void load();
    void save();

    void fetchStripUrl(QUrl stripUrl = QUrl());
    void abortFetching();
    void read();

protected:
    virtual QUrl stripSourceUrl() const = 0;

private slots:
    void onFetchFinished();
    void parse();

signals:
    void fetchStarted();
    void dataParsed();
    void networkError();
    void parsingError();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);

    void newStripChanged(Comic* comic);
    void errorChanged(Comic* comic);
    void fetchingChanged(Comic* comic);

protected:
    static const int _minFetchDelay;
    ComicDatabaseResource* dbResource;
    QUrl m_stripUrl;
    QNetworkAccessManager* m_networkManager;
    QNetworkReply* m_currentReply;
    bool m_favorite;
    bool m_newStrip;
    bool m_error;
    bool m_fetching;
    QDateTime m_fetchTime;
};

#endif // COMIC_H
