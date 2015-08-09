/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LoadingArtist.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

LoadingArtist::LoadingArtist(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("loadingartist");
    m_info.name           = QString("Loading Artist");
    m_info.color          = QColor(253, 104, 1);
    m_info.authors        = QStringList("Gregor Czaykowski");
    m_info.homepage       = QUrl("http://www.loadingartist.com/");
    m_info.country        = QLocale::NewZealand;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2011-01-04", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.loadingartist.com/latest");
}

QUrl LoadingArtist::extractStripImageUrl(QByteArray data)
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
