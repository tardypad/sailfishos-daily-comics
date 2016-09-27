/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "SadSacks.h"

#include <QDebug>

SadSacks::SadSacks(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("sadsacks");
    m_info.name           = QString("Sad Sacks");
    m_info.color          = QColor(167, 139, 118);
    m_info.authors        = QStringList() << "James \"Wiz\" Wallace" << "Johnny \"Wasabi\" Larocque";
    m_info.homepage       = QUrl("http://www.sadsacks.ca/");
    m_info.country        = QLocale::Canada;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://johnnylarocque.com/sadsacks/");
}

QUrl SadSacks::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(images/comic/[^\"]*)\"");
}
