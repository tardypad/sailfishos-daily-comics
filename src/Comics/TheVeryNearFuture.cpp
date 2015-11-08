/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheVeryNearFuture.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

TheVeryNearFuture::TheVeryNearFuture(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("theverynearfuture");
    m_info.name           = QString("The Very Near Future");
    m_info.color          = QColor(70, 120, 129);
    m_info.homepage       = QUrl("http://theverynearfuture.com/");
    m_info.language       = QLocale::English;
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://theverynearfuture.com/rss");
}

QUrl TheVeryNearFuture::extractStripImageUrl(QByteArray data)
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
