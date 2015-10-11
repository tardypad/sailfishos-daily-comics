/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FredBasset.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

FredBasset::FredBasset(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("fredbasset");
    m_info.name           = QString("Fred Basset");
    m_info.color          = QColor(203, 176, 61);
    m_info.authors        = QStringList() << "Alex Graham" << "Michael Martin";
    m_info.homepage       = QUrl("http://www.gocomics.com/fredbasset/");
    m_info.country        = QLocale::UnitedKingdom;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1963-07-08", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/fredbasset/");
}

QUrl FredBasset::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
