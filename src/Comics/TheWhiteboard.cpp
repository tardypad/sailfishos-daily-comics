/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheWhiteboard.h"

#include <QDebug>

TheWhiteboard::TheWhiteboard(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("thewhiteboard");
    m_info.name           = QString("The Whiteboard");
    m_info.color          = QColor(94, 204, 255);
    m_info.authors        = QStringList("\"Doc\" Nickel");
    m_info.homepage       = QUrl("http://www.the-whiteboard.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.the-whiteboard.com/");
}

QUrl TheWhiteboard::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img SRC=\"([^\"]*)\"");
}
