/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Erzaehlmirnix.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

Erzaehlmirnix::Erzaehlmirnix(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("erzaehlmirnix");
    m_info.name           = QString("Erzaehlmirnix");
    m_info.color          = QColor(188, 197, 192);
    m_info.authors        = QStringList("Nadja Hermann");
    m_info.homepage       = QUrl("https://erzaehlmirnix.wordpress.com/");
    m_info.country        = QLocale::Germany;
    m_info.language       = QLocale::German;
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("https://erzaehlmirnix.wordpress.com/");
}

QUrl Erzaehlmirnix::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*erzaehlmirnix.files.wordpress.com[^\"]*)\"");
    QRegularExpressionMatchIterator matchIterator = reg.globalMatch(html);

    if (!matchIterator.hasNext())
        return QUrl();

    matchIterator.next();

    if (!matchIterator.hasNext())
        return QUrl();

    QRegularExpressionMatch match = matchIterator.next();

    QString src = match.captured(1);

    return QUrl(src);
}
