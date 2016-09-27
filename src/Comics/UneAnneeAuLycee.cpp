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
    m_info.id             = QString("uneanneeaulycee");
    m_info.name           = QString("Une année au lycée");
    m_info.color          = QColor(181, 181, 181);
    m_info.authors        = QStringList("Fabrice Erre");
    m_info.homepage       = QUrl("http://uneanneeaulycee.blog.lemonde.fr/");
    m_info.language       = QLocale::French;
    m_info.stripSourceUrl = QUrl("http://uneanneeaulycee.blog.lemonde.fr/feed/");
}

QUrl UneAnneeAuLycee::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/files/[^\"]*)\"");
}
