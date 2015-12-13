/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheGamerCat.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

TheGamerCat::TheGamerCat(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("thegamercat");
    m_info.name           = QString("The GaMERCaT");
    m_info.color          = QColor(179, 179, 179);
    m_info.authors        = QStringList("Samantha Whitten");
    m_info.homepage       = QUrl("http://www.thegamercat.com");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2011-06-10", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.thegamercat.com/");
}

QUrl TheGamerCat::extractStripImageUrl(QByteArray data)
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
