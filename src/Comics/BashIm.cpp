/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "BashIm.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

BashIm::BashIm(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("bashim");
    m_info.name           = QString("bash.im");
    m_info.color          = QColor(81, 86, 178);
    m_info.authors        = QStringList("Lin");
    m_info.homepage       = QUrl("http://bash.im/comics/");
    m_info.country        = QLocale::Russia;
    m_info.language       = QLocale::Russian;
    m_info.startDate      = QDate::fromString("2007-08-01", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://bash.im/comics/");
}

QUrl BashIm::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<div id=\"the_strip\"><img src=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
