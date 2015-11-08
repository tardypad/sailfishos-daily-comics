/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Dirkjan.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Dirkjan::Dirkjan(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("dirkjan");
    m_info.name           = QString("Dirkjan");
    m_info.color          = QColor(255, 127, 0);
    m_info.authors        = QStringList("Mark Retera");
    m_info.homepage       = QUrl("http://dirkjan.nl/");
    m_info.country        = QLocale::Netherlands;
    m_info.language       = QLocale::Dutch;
    m_info.startDate      = QDate::fromString("1989", "yyyy");
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://dirkjan.nl/");
}

QUrl Dirkjan::extractStripImageUrl(QByteArray data)
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
