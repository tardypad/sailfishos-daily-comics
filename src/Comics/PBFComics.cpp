/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PBFComics.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

PBFComics::PBFComics(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("pbfcomics");
    m_info.name           = QString("The Perry Bible Fellowship");
    m_info.color          = QColor(217, 201, 168);
    m_info.authors        = QStringList("Nicholas Gurewitch");
    m_info.homepage       = QUrl("http://pbfcomics.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2001", "yyyy");
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://pbfcomics.com/feed/feed.xml");
}

QUrl PBFComics::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("src=&quot;([^&]*/archive_b/[^&]*)&quot;");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
