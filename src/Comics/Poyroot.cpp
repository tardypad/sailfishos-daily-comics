/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Poyroot.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Poyroot::Poyroot(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("poyroot");
    m_info.name           = QString("Pöyrööt");
    m_info.color          = QColor(160, 207, 79);
    m_info.authors        = QStringList() << "Arttu Seppälä" << "Liisa Seppälä" << "Tiia Pelkola";
    m_info.homepage       = QUrl("http://www.poyroot.fi");
    m_info.country        = QLocale::Finland;
    m_info.language       = QLocale::Finnish;
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.poyroot.fi/sarjakuvat/");
}

QUrl Poyroot::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/poyroot_[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
