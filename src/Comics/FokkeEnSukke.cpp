/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FokkeEnSukke.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

FokkeEnSukke::FokkeEnSukke(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("fokkeensukke");
    m_info.name           = QString("Fokke en Sukke");
    m_info.color          = QColor(213, 26, 33);
    m_info.authors        = QStringList() << "Jean-Marc van Tol" << "John Reid" << "Bastiaan Geleijnse";
    m_info.homepage       = QUrl("http://foksuk.nl/");
    m_info.country        = QLocale::Netherlands;
    m_info.language       = QLocale::Dutch;
    m_info.startDate      = QDate::fromString("1994", "yyyy");
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://foksuk.nl/");
}

QUrl FokkeEnSukke::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(content/formfield_files/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://foksuk.nl/" + src);
}
