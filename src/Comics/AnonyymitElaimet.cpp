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
    m_info.id = QString("anonyymitelaimet");
}

QUrl AnonyymitElaimet::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/webkuva/sarjis[^\"]*)\"");
}
