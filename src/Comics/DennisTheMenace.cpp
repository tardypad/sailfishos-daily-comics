/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DennisTheMenace.h"

#include <QDebug>

DennisTheMenace::DennisTheMenace(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("dennisthemenace");
    m_info.name           = QString("Dennis The Menace");
    m_info.color          = QColor(253, 219, 0);
    m_info.authors        = QStringList() << "Hank Ketcham" << "Marcus Hamilton" << "Ron Ferdinand";
    m_info.homepage       = QUrl("http://dennisthemenace.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://dennisthemenace.com/");
}

QUrl DennisTheMenace::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<meta property=\"og:image\" content=\"([^\"]*)\"");
}
