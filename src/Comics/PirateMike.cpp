/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PirateMike.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

PirateMike::PirateMike(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("piratemike");
    m_info.name           = QString("Pirate Mike");
    m_info.color          = QColor(255, 71, 33);
    m_info.authors        = QStringList("Brad Perri");
    m_info.homepage       = QUrl("http://piratemikecomics.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2012-04-04", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://piratemikecomics.com/");
}

QUrl PirateMike::extractStripImageUrl(QByteArray data)
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
