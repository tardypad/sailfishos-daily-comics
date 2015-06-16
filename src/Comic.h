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
#include <QTimer>

class QNetworkAccessManager;
class QNetworkReply;
class ComicDatabaseResource;
class ComicFileResource;

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
    QUrl extractedStripUrl() const { return m_extractedStripUrl; }
    int fetchingProgress() const { return m_fetchingProgress; }

    void setFavorite(const bool favorite) { m_favorite = favorite; emit favoriteChanged(this);}
    void setNewStrip(const bool newStrip) { m_newStrip = newStrip; emit newStripChanged(this); }
    void setError(const bool error) { m_error = error; emit errorChanged(this);}
    void setFetching(const bool fetching) { m_fetching = fetching; emit fetchingChanged(this); }
    void setFetchingProgress(const bool fetchingProgress) { m_fetchingProgress = fetchingProgress; emit fetchingProgressChanged(this); }
    void setFetchTime(const QDateTime fetchTime) { m_fetchTime = fetchTime; }
    void setStripUrl(const QUrl stripUrl) { m_stripUrl = stripUrl; }
    void setExtractedStripUrl(const QUrl extractedStripUrl) { m_extractedStripUrl = extractedStripUrl; }

    void load();
    void save();

    void fetchStrip(QUrl stripUrl = QUrl());
    QString stripPath() const;
    void abortFetching();
    void read();

protected:
    virtual QUrl stripSourceUrl() const = 0;
    void parse();
    void fetchStripImage(QUrl stripImageUrl);
    QUrl redirectedToUrl();
    bool stripImageDownloaded();

private slots:
    void onFetchFinished();
    void onFetchImageFinished();
    void timeout();
    void updateFetchingProgress(qint64 bytesReceived, qint64 bytesTotal);

signals:
    void fetchStarted();
    void fetchFinished();
    void networkError();
    void parsingError();
    void savingError();
    void downloadProgress(qint64 bytesReceived, qint64 bytesTotal);

    void favoriteChanged(Comic* comic);
    void newStripChanged(Comic* comic);
    void errorChanged(Comic* comic);
    void fetchingChanged(Comic* comic);
    void fetchingProgressChanged(Comic* comic);

protected:
    static const int _minFetchDelay;
    static const int _timeout;

    ComicDatabaseResource* dbResource;
    ComicFileResource* fileResource;
    QNetworkAccessManager* m_networkManager;
    QNetworkReply* m_currentReply;
    QTimer* m_timeoutTimer;

    QUrl m_extractedStripUrl;
    QUrl m_stripUrl;
    bool m_favorite;
    bool m_newStrip;
    bool m_error;
    bool m_fetching;
    QDateTime m_fetchTime;
    int m_fetchingProgress;
};

#endif // COMIC_H
