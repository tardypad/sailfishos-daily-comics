/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PhdComics.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

PhdComics::PhdComics(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("phdcomics");
    m_info.name           = QString("Piled Higher and Deeper");
    m_info.color          = QColor(82, 105, 125);
    m_info.authors        = QStringList("Jorge Cham");
    m_info.homepage       = QUrl("http://phdcomics.com/");
    m_info.country        = QLocale::Panama;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1997-10-27", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://phdcomics.com/comics.php");
}

QUrl PhdComics::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img id=comic[^>]*src=([^ ]*)");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
