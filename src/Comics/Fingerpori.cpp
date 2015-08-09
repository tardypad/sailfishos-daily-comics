/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Fingerpori.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Fingerpori::Fingerpori(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("fingerpori");
    m_info.name           = QString("Fingerpori");
    m_info.color          = QColor(148, 8, 11);
    m_info.authors        = QStringList("Pertti Jarla");
    m_info.homepage       = QUrl("http://fingerpori.org");
    m_info.country        = QLocale::Finland;
    m_info.language       = QLocale::Finnish;
    m_info.startDate      = QDate::fromString("2007-02", "yyyy-MM");
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.hs.fi/m/fingerpori/");
}

QUrl Fingerpori::extractStripImageUrl(QByteArray data)
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
