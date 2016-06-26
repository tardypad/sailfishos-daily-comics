/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "WrongHands.h"

#include <QDebug>

WrongHands::WrongHands(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("wronghands");
    m_info.name           = QString("Wrong Hands");
    m_info.color          = QColor(76, 121, 188);
    m_info.authors        = QStringList("John Atkinson");
    m_info.homepage       = QUrl("https://wronghands1.com/");
    m_info.country        = QLocale::Canada;
    m_info.language       = QLocale::English;
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("https://wronghands1.com/feed/");
}

QUrl WrongHands::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*wronghands1.files.wordpress.com/[^\"]*)\"");
}
