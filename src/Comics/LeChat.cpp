/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LeChat.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

LeChat::LeChat(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("lechat");
    m_info.name           = QString("Le Chat");
    m_info.color          = QColor(38, 203, 171);
    m_info.authors        = QStringList("Philippe Geluck");
    m_info.homepage       = QUrl("http://geluck.com/");
    m_info.country        = QLocale::Belgium;
    m_info.language       = QLocale::French;
    m_info.startDate      = QDate::fromString("1983-03-22", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://geluck.com/dessin.html");
}

QUrl LeChat::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/strip/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://geluck.com/" + src);
}
