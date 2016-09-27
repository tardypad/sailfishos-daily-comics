/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "CalvinAndHobbes.h"

#include <QDebug>

CalvinAndHobbes::CalvinAndHobbes(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("calvinandhobbes");
    m_info.name           = QString("Calvin and Hobbes");
    m_info.color          = QColor(236, 29, 35);
    m_info.authors        = QStringList("Bill Watterson");
    m_info.homepage       = QUrl("http://www.calvinandhobbes.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/calvinandhobbes/");
}

QUrl CalvinAndHobbes::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
