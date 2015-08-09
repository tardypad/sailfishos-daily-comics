/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "SadSacks.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

SadSacks::SadSacks(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("sadsacks");
    m_info.name           = QString("Sad Sacks");
    m_info.color          = QColor(188, 160, 139);
    m_info.authors        = QStringList() << "James \"Wiz\" Wallace" << "Johnny \"Wasabi\" Larocque";
    m_info.homepage       = QUrl("http://www.sadsacks.ca/");
    m_info.country        = QLocale::Canada;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2015-01-05", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.sadsacks.ca/");
}

QUrl SadSacks::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(images/comic/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://www.sadsacks.ca/" + src);
}
