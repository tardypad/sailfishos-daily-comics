/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FoxTrot.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

FoxTrot::FoxTrot(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("foxtrot");
    m_info.name           = QString("FoxTrot");
    m_info.color          = QColor(250, 203, 123);
    m_info.authors        = QStringList("Bill Amend");
    m_info.homepage       = QUrl("http://www.foxtrot.com");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1988-04-10", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/foxtrot");
}

QUrl FoxTrot::extractStripImageUrl(QByteArray data)
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
