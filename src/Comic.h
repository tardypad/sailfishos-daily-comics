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
    virtual QString author() const = 0;
    virtual QUrl homepage() const = 0;
    virtual QLocale::Country country() const = 0;
    virtual QLocale::Language language() const = 0;
    virtual QDate startDate() const = 0;
    virtual QDate endDate() const = 0;
    virtual QUrl extractStripUrl(QByteArray data) = 0;

    QUrl currentStripUrl() const { return m_currentStripUrl; }
    bool favorite() const { return m_favorite; }
    bool newStrip() const { return m_newStrip; }
    bool error() const { return m_error; }
    bool fetching() const { return m_fetching; }
    QDateTime lastStripFetchTime() const { return m_lastStripFetchTime; }
    QUrl lastStripUrl() const { return m_lastStripUrl; }

    void setFavorite(const bool favorite) { m_favorite = favorite; }
    void setNewStrip(const bool newStrip) { m_newStrip = newStrip; emit newStripChanged(this); }
    void setError(const bool error) { m_error = error; emit errorChanged(this);}
    void setFetching(const bool fetching) { m_fetching = fetching; emit fetchingChanged(this); }
    void setLastStripFetchTime(const QDateTime lastStripFetchTime) { m_lastStripFetchTime = lastStripFetchTime; }
    void setLastStripUrl(const QUrl lastStripUrl){ m_lastStripUrl = lastStripUrl; }

    void load();
    void save();

    void fetchCurrentStripUrl();
    void abortFetching();

protected:
    virtual QUrl stripSourceUrl() const = 0;

    void setCurrentStripUrl(const QUrl currentStripUrl) { m_currentStripUrl = currentStripUrl; }

private slots:
    void parse();
    void flagError();
    void flagStoppedFetching();

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
    ComicDatabaseResource* dbResource;
    QUrl m_currentStripUrl;
    QNetworkAccessManager* m_networkManager;
    QNetworkReply* m_currentReply;
    bool m_favorite;
    bool m_newStrip;
    bool m_error;
    bool m_fetching;
    QDateTime m_lastStripFetchTime;
    QUrl m_lastStripUrl;
};

#endif // COMIC_H
