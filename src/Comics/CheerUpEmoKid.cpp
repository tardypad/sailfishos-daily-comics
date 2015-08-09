/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "CheerUpEmoKid.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

CheerUpEmoKid::CheerUpEmoKid(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("cheerupemokid");
    m_info.name           = QString("Cheer Up, Emo Kid");
    m_info.color          = QColor(51, 51, 51);
    m_info.authors        = QStringList("Enzo");
    m_info.homepage       = QUrl("http://www.cheerupemokid.com/");
    m_info.country        = QLocale::Canada;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2008-10-10", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.cheerupemokid.com/");
}

QUrl CheerUpEmoKid::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
