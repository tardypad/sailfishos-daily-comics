/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "HagarTheHorrible.h"

#include <QDebug>

HagarTheHorrible::HagarTheHorrible(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("hagarthehorrible");
    m_info.name           = QString("Hägar the Horrible");
    m_info.color          = QColor(192, 143, 48);
    m_info.authors        = QStringList() << "Dik Browne" << "Chris Browne";
    m_info.homepage       = QUrl("http://hagarthehorrible.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://hagarthehorrible.com/");
}

QUrl HagarTheHorrible::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*content\\.php[^\"]*)\"");
}
