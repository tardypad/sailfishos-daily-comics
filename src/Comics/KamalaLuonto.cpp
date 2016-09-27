/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "KamalaLuonto.h"

#include <QDebug>

KamalaLuonto::KamalaLuonto(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("kamalaluonto");
    m_info.name           = QString("Kamala Luonto");
    m_info.color          = QColor(196, 138, 75);
    m_info.authors        = QStringList("Jarkko Vehniäisen");
    m_info.homepage       = QUrl("http://kamalaluonto.com/");
    m_info.country        = QLocale::Finland;
    m_info.language       = QLocale::Finnish;
    m_info.stripSourceUrl = QUrl("http://www.iltasanomat.fi/kamalaluonto/");
}

QUrl KamalaLuonto::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "data-original=\"([^\"]*)\"");
}
