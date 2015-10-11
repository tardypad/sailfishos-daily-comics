/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FowlLanguageComics.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

FowlLanguageComics::FowlLanguageComics(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("fowllanguagecomics");
    m_info.name           = QString("Fowl Language Comics");
    m_info.color          = QColor(219, 232, 212);
    m_info.authors        = QStringList("Brian Gordon");
    m_info.homepage       = QUrl("http://www.fowllanguagecomics.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2013-07-22", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.fowllanguagecomics.com/?bypass-regular-homepage-cache-problem");
}

QUrl FowlLanguageComics::extractStripImageUrl(QByteArray data)
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
