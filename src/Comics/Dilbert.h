/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef DILBERT_H
#define DILBERT_H

#include "../Comic.h"

#include <QLocale>
#include <QDate>
#include <QColor>

class Dilbert : public Comic
{
    Q_OBJECT

public:
    explicit Dilbert(QObject *parent = 0);

    virtual inline QString id() const { return _id; }
    virtual inline QString name() const { return _name; }
    virtual inline QColor color() const { return _color; }
    virtual inline QString author() const { return _author; }
    virtual inline QUrl homepage() const { return _homepage; }
    virtual inline QLocale::Country country() const { return _country; }
    virtual inline QLocale::Language language() const { return _language; }
    virtual inline QDate startDate() const { return _startDate; }
    virtual inline QDate endDate() const { return _endDate; }

    virtual QUrl extractStripUrl(QByteArray data);

protected:
    virtual inline QUrl stripSourceUrl() const { return _stripSourceUrl; }

private:
    static const QString _id;
    static const QString _name;
    static const QColor _color;
    static const QString _author;
    static const QUrl _homepage;
    static const QLocale::Country _country;
    static const QLocale::Language _language;
    static const QDate _startDate;
    static const QDate _endDate;
    static const QUrl _stripSourceUrl;
};

#endif // DILBERT_H
