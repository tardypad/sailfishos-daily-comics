/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "BerkeleyMews.h"

#include <QDebug>

BerkeleyMews::BerkeleyMews(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("berkeleymews");
    m_info.name           = QString("Berkeley Mews");
    m_info.color          = QColor(237, 233, 195);
    m_info.authors        = QStringList("Ben Zaehringer");
    m_info.homepage       = QUrl("http://www.berkeleymews.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.berkeleymews.com/");
}

QUrl BerkeleyMews::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/comics/[^\"]*)\"", 2);
}
