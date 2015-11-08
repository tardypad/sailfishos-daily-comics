/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheAwkwardYeti.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

TheAwkwardYeti::TheAwkwardYeti(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("theawkwardyeti");
    m_info.name           = QString("The Awkward Yeti");
    m_info.color          = QColor(255, 200, 47);
    m_info.authors        = QStringList("Nick Seluk");
    m_info.homepage       = QUrl("http://theawkwardyeti.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2012-09-12", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://theawkwardyeti.com/");
}

QUrl TheAwkwardYeti::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<div id=\"comic\">\\s*<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
