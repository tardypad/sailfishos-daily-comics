/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Sinfest.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Sinfest::Sinfest(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("sinfest");
    m_info.name           = QString("Sinfest");
    m_info.color          = QColor(253, 251, 78);
    m_info.authors        = QStringList("Tatsuya Ishida");
    m_info.homepage       = QUrl("http://sinfest.net/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2000-01-17", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.sinfest.net/");
}

QUrl Sinfest::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*/comics/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://www.sinfest.net/" + src);
}
