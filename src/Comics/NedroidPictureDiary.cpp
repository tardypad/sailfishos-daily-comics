/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "NedroidPictureDiary.h"

#include <QDebug>

NedroidPictureDiary::NedroidPictureDiary(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("nedroidpicturediary");
    m_info.name           = QString("Nedroid Picture Diary");
    m_info.color          = QColor(120, 157, 202);
    m_info.authors        = QStringList("Anthony Clark");
    m_info.homepage       = QUrl("http://nedroid.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2005-09", "yyyy-MM");
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://nedroid.com/feed/");
}

QUrl NedroidPictureDiary::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/comic/[^\"]*)\"");
}
