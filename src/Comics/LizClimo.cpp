/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LizClimo.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

LizClimo::LizClimo(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("lizclimo");
    m_info.name           = QString("Liz Climo");
    m_info.color          = QColor(233, 142, 139);
    m_info.authors        = QStringList("Liz Climo");
    m_info.homepage       = QUrl("http://lizclimo.tumblr.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2002-09-05", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://lizclimo.tumblr.com/rss");
}

QUrl LizClimo::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("&lt;img[^&]*src=\"([^\"]*media.tumblr.com/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
