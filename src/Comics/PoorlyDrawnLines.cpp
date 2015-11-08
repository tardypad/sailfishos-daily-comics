/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "PoorlyDrawnLines.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

PoorlyDrawnLines::PoorlyDrawnLines(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("poorlydrawnlines");
    m_info.name           = QString("Poorly Drawn Lines");
    m_info.color          = QColor(211, 229, 229);
    m_info.authors        = QStringList("Reza Farazmand");
    m_info.homepage       = QUrl("http://poorlydrawnlines.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://feeds.feedburner.com/PoorlyDrawnLines?format=xml");
}

QUrl PoorlyDrawnLines::extractStripImageUrl(QByteArray data)
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
