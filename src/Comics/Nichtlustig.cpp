/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Nichtlustig.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Nichtlustig::Nichtlustig(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("nichtlustig");
    m_info.name           = QString("Nichtlustig");
    m_info.color          = QColor(180, 0, 1);
    m_info.authors        = QStringList("Joscha Sauer");
    m_info.homepage       = QUrl("http://nichtlustig.de/");
    m_info.country        = QLocale::Germany;
    m_info.language       = QLocale::German;
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://nichtlustig.de/main.html");
}

QUrl Nichtlustig::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<link rel=\"image_src\" href=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
