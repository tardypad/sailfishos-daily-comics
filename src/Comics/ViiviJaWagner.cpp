/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ViiviJaWagner.h"

#include <QDebug>

ViiviJaWagner::ViiviJaWagner(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("viivijawagner");
    m_info.name           = QString("Viivi ja Wagner");
    m_info.color          = QColor(222, 42, 131);
    m_info.authors        = QStringList("Jussi \"Juba\" Tuomola");
    m_info.homepage       = QUrl("http://www.viivijawagner.net/");
    m_info.country        = QLocale::Finland;
    m_info.language       = QLocale::Finnish;
    m_info.stripSourceUrl = QUrl("http://www.hs.fi/m/viivijawagner/");
}

QUrl ViiviJaWagner::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/webkuva/[^\"]*)\"");
}
