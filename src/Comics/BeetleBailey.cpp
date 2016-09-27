/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "BeetleBailey.h"

#include <QDebug>

BeetleBailey::BeetleBailey(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("beetlebailey");
    m_info.name           = QString("Beetle Bailey");
    m_info.color          = QColor(174, 169, 137);
    m_info.authors        = QStringList("Mort Walker");
    m_info.homepage       = QUrl("http://beetlebailey.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://beetlebailey.com/");
}

QUrl BeetleBailey::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<meta property=\"og:image\" content=\"([^\"]*)\"");
}
