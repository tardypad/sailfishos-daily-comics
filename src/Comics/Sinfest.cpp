/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Sinfest.h"

#include <QDebug>

Sinfest::Sinfest(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("sinfest");
    m_info.name           = QString("Sinfest");
    m_info.color          = QColor(253, 251, 78);
    m_info.authors        = QStringList("Tatsuya Ishida");
    m_info.homepage       = QUrl("http://sinfest.net/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.sinfest.net/");
}

QUrl Sinfest::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/comics/[^\"]*)\"");
}
