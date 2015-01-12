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
    Q_PROPERTY(QString comicId READ comicId WRITE setComicId NOTIFY comicIdChanged)
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QString author READ author NOTIFY authorChanged)
    Q_PROPERTY(QUrl homepage READ homepage NOTIFY homepageChanged)
    Q_PROPERTY(QString country READ country NOTIFY countryChanged)
    Q_PROPERTY(QString language READ language NOTIFY languageChanged)
    Q_PROPERTY(QDate startDate READ startDate NOTIFY startDateChanged)
    Q_PROPERTY(QDate endDate READ endDate NOTIFY endDateChanged)
    Q_PROPERTY(QUrl currentStripUrl READ currentStripUrl NOTIFY currentStripUrlChanged)

public:
    explicit ComicProxy(QObject *parent = 0);

    QString comicId() const;
    QString name() const;
    QString author() const;
    QUrl homepage() const;
    QString country() const;
    QString language() const;
    QDate startDate() const;
    QDate endDate() const;
    QUrl currentStripUrl();

    void setComicId(const QString comicId);

    Q_INVOKABLE void fetchCurrentStrip();

signals:
    void comicIdChanged();
    void nameChanged();
    void authorChanged();
    void homepageChanged();
    void countryChanged();
    void languageChanged();
    void startDateChanged();
    void endDateChanged();
    void currentStripUrlChanged();

private:
    Comic* m_comic;
};

#endif // COMICPROXY_H
