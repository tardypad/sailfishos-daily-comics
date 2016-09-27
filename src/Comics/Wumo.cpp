/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Wumo.h"

#include <QDebug>

Wumo::Wumo(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("wumo");
    m_info.name           = QString("Wumo");
    m_info.color          = QColor(139, 200, 8);
    m_info.authors        = QStringList() << "Mikael Wulff" << "Anders Morgenthaler";
    m_info.homepage       = QUrl("http://wumo.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://wumo.com/wumo?view=rss");
}

QUrl Wumo::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/img/wumo/[^\"]*)\"");
}
