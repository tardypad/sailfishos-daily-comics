/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "WhatAWonderfulWorld.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

WhatAWonderfulWorld::WhatAWonderfulWorld(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("whatawonderfulworld");
    m_info.name           = QString("What a wonderful world!");
    m_info.color          = QColor(195, 143, 189);
    m_info.authors        = QStringList("Philippe Chappuis \"Zep\"");
    m_info.homepage       = QUrl("http://zepworld.blog.lemonde.fr/");
    m_info.country        = QLocale::Switzerland;
    m_info.language       = QLocale::French;
    m_info.startDate      = QDate::fromString("2014-11-01", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://zepworld.blog.lemonde.fr/feed/atom/");
}

QUrl WhatAWonderfulWorld::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*/files/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
