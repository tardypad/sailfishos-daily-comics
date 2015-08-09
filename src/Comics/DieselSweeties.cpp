/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DieselSweeties.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

DieselSweeties::DieselSweeties(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("dieselsweeties");
    m_info.name           = QString("Diesel Sweeties");
    m_info.color          = QColor(116, 141, 66);
    m_info.authors        = QStringList("Richard Stevens III");
    m_info.homepage       = QUrl("http://dieselsweeties.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2000-04", "yyyy-MM");
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://dieselsweeties.com/");
}

QUrl DieselSweeties::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/hstrips/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://www.dieselsweeties.com/" + src);
}
