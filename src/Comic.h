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
#include <QColor>
#include <QLocale>
#include <QDateTime>
#include <QTimer>

class QNetworkAccessManager;
class QNetworkReply;
class ComicDatabaseResource;
class ComicPluginResource;
class ComicStripFileResource;

struct ComicInfo {
    QString name;
    QColor color;
    QStringList authors;
    QUrl homepage;
    QLocale::Language language;
    QUrl stripSourceUrl;

    ComicInfo() {
        name = QString();
        color = QColor();
        authors = QStringList();
        homepage = QString();
        language = QLocale::AnyLanguage;
        stripSourceUrl = QUrl();
    }
};

class Comic : public QObject
{
    Q_OBJECT

public:
    explicit Comic(QString id, QObject *parent = 0);
    ~Comic();

    QString id() const { return m_id; }
    QString coverPath() const { return m_coverPath; }
    QString examplePath() const { return m_examplePath; }

    QString name() const { return m_info.name; }
    QColor color() const { return m_info.color; }
    QStringList authors() const { return m_info.authors; }
    QUrl homepage() const { return m_info.homepage; }
    QLocale::Language language() const { return m_info.language; }
    QUrl stripSourceUrl() const { return m_info.stripSourceUrl; }
    ComicInfo getInfo() const { return m_info; }

    QUrl stripImageUrl() const { return m_stripImageUrl; }
    bool favorite() const { return m_favorite; }
    bool newStrip() const { return m_newStrip; }
    bool error() const { return m_error; }
    bool fetching() const { return m_fetching; }
    QDateTime fetchTime() const { return m_fetchTime; }
    QUrl extractedStripImageUrl() const { return m_extractedStripImageUrl; }
    int fetchingProgress() const { return m_fetchingProgress; }
    bool isAnimatedDefined() const { return m_isAnimatedDefined; }
    int random() const { return m_random; }

    void setInfo(const ComicInfo info) { m_info = info; }
    void setCoverPath(const QString coverPath) { m_coverPath = coverPath; }
    void setExamplePath(const QString examplePath) { m_examplePath = examplePath; }

    void setFavorite(const bool favorite) { m_favorite = favorite; emit favoriteChanged(this);}
    void setNewStrip(const bool newStrip) { m_newStrip = newStrip; emit newStripChanged(this); }
    void setError(const bool error) { m_error = error; emit errorChanged(this);}
    void setFetching(const bool fetching) { m_fetching = fetching; emit fetchingChanged(this); }
    void setFetchingProgress(const bool fetchingProgress) { m_fetchingProgress = fetchingProgress; emit fetchingProgressChanged(this); }
    void setFetchTime(const QDateTime fetchTime) { m_fetchTime = fetchTime; }
    void setStripImageUrl(const QUrl stripImageUrl) { m_stripImageUrl = stripImageUrl; }
    void setExtractedStripImageUrl(const QUrl extractedStripImageUrl) { m_extractedStripImageUrl = extractedStripImageUrl; }
    void setIsAnimatedDefined(const bool isAnimatedDefined) { m_isAnimatedDefined = isAnimatedDefined; }

    void load();
    void save();

    void fetchStrip();
    QString stripImagePath() const;
    bool animated();
    QString sortName() const;
    void abortFetching();
    void read();
    bool saveToGallery();
    bool stripImageDownloaded();

protected:
    void fetchStripSource(QUrl stripSrcUrl = QUrl());
    void fetchStripImage(QUrl stripImageUrl);
    QUrl redirectedToUrl();

private slots:
    void onFetchStripSourceFinished();
    void onFetchStripImageFinished();
    void timeout();
    void updateFetchingProgress(qint64 bytesReceived, qint64 bytesTotal);

signals:
    void fetchStarted();
    void fetchSucceeded();
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
    static const QStringList _prefixes;

    QString m_id;
    QString m_coverPath;
    QString m_examplePath;
    ComicInfo m_info;

    ComicDatabaseResource* dbResource;
    ComicPluginResource* pluginResource;
    ComicStripFileResource* stripFileResource;

    QNetworkAccessManager* m_networkManager;
    QNetworkReply* m_currentReply;
    QTimer* m_timeoutTimer;

    int m_random;
    QUrl m_extractedStripImageUrl;
    QUrl m_stripImageUrl;
    bool m_favorite;
    bool m_newStrip;
    bool m_error;
    bool m_fetching;
    QDateTime m_fetchTime;
    int m_fetchingProgress;
    bool m_animated;
    bool m_isAnimatedDefined;
};

#endif // COMIC_H
