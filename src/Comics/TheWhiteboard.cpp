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
    m_info.id = QString("thewhiteboard");
}

QUrl TheWhiteboard::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img SRC=\"([^\"]*)\"");
}
