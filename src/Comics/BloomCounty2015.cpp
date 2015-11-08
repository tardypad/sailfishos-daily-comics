/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "BloomCounty2015.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

BloomCounty2015::BloomCounty2015(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("bloomcounty2015");
    m_info.name           = QString("Bloom County 2015");
    m_info.color          = QColor(190, 154, 224);
    m_info.authors        = QStringList("Berkeley Breathed");
    m_info.homepage       = QUrl("http://www.berkeleybreathed.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2015-07-13", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/bloom-county");
}

QUrl BloomCounty2015::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
