/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FokkeEnSukke.h"

#include <QDebug>

FokkeEnSukke::FokkeEnSukke(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("fokkeensukke");
}

QUrl FokkeEnSukke::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(content/formfield_files/[^\"]*)\"");
}
