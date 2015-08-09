/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ExtraOrdinary.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

ExtraOrdinary::ExtraOrdinary(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("extraordinary");
    m_info.name           = QString("Extra Ordinary");
    m_info.color          = QColor(175, 175, 175);
    m_info.authors        = QStringList("Li Chen");
    m_info.homepage       = QUrl("http://www.exocomics.com/");
    m_info.country        = QLocale::NewZealand;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2009", "yyyy");
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.exocomics.com/");
}

QUrl ExtraOrdinary::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/comics/comics/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
