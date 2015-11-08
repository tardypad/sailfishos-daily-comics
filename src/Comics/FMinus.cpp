/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FMinus.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

FMinus::FMinus(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("fminus");
    m_info.name           = QString("F Minus");
    m_info.color          = QColor(158, 44, 34);
    m_info.authors        = QStringList("Tony Carrillo");
    m_info.homepage       = QUrl("http://www.fminus.net/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2005-05-10", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/fminus");
}

QUrl FMinus::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
