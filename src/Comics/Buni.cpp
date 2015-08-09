/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Buni.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Buni::Buni(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("buni");
    m_info.name           = QString("Buni");
    m_info.color          = QColor(87, 110, 152);
    m_info.authors        = QStringList("Ryan Pagelow");
    m_info.homepage       = QUrl("http://www.bunicomic.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2010-01-01", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.bunicomic.com/");
}

QUrl Buni::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<div id=\"comic\">\n<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
