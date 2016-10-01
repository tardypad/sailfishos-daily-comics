/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "UneAnneeAuLycee.h"

#include <QDebug>

UneAnneeAuLycee::UneAnneeAuLycee(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("uneanneeaulycee");
}

QUrl UneAnneeAuLycee::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/files/[^\"]*)\"");
}
