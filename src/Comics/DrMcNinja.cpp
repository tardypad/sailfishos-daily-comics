/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DrMcNinja.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

DrMcNinja::DrMcNinja(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("drmcninja");
    m_info.name           = QString("The Adventures of Dr. McNinja");
    m_info.color          = QColor(176, 176, 176);
    m_info.authors        = QStringList("Christopher Hastings");
    m_info.homepage       = QUrl("http://drmcninja.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2004-08-03", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://drmcninja.com/");
}

QUrl DrMcNinja::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/comics/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
