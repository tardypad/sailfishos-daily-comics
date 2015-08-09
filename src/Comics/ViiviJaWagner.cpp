/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ViiviJaWagner.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

ViiviJaWagner::ViiviJaWagner(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("viivijawagner");
    m_info.name           = QString("Viivi ja Wagner");
    m_info.color          = QColor(222, 42, 131);
    m_info.authors        = QStringList("Jussi \"Juba\" Tuomola");
    m_info.homepage       = QUrl("http://www.viivijawagner.net/");
    m_info.country        = QLocale::Finland;
    m_info.language       = QLocale::Finnish;
    m_info.startDate      = QDate::fromString("1997-10-06", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.hs.fi/m/viivijawagner/");
}

QUrl ViiviJaWagner::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/webkuva/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
