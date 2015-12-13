/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheWhiteboard.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

TheWhiteboard::TheWhiteboard(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("thewhiteboard");
    m_info.name           = QString("The Whiteboard");
    m_info.color          = QColor(94, 204, 255);
    m_info.authors        = QStringList("\"Doc\" Nickel");
    m_info.homepage       = QUrl("http://www.the-whiteboard.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2002-06-18", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.the-whiteboard.com/");
}

QUrl TheWhiteboard::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img SRC=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://www.the-whiteboard.com/" + src);
}
