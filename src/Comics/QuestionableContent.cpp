/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "QuestionableContent.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

QuestionableContent::QuestionableContent(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("questionablecontent");
    m_info.name           = QString("Questionable Content");
    m_info.color          = QColor(118, 161, 178);
    m_info.authors        = QStringList("Jeph Jacques");
    m_info.homepage       = QUrl("http://questionablecontent.net/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2003-08-01", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.questionablecontent.net/QCRSS.xml");
}

QUrl QuestionableContent::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/comics/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
