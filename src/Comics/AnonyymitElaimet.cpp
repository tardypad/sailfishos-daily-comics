/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "AnonyymitElaimet.h"

#include <QDebug>

AnonyymitElaimet::AnonyymitElaimet(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("anonyymitelaimet");
    m_info.name           = QString("Anonyymit Eläimet");
    m_info.color          = QColor(221, 234, 181);
    m_info.authors        = QStringList("Joonas Lehtimäki");
    m_info.homepage       = QUrl("http://anonyymitelaimet.com");
    m_info.language       = QLocale::Finnish;
    m_info.stripSourceUrl = QUrl("http://nyt.fi/aihe/anonyymitelaimet/");
}

QUrl AnonyymitElaimet::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/webkuva/sarjis[^\"]*)\"");
}
