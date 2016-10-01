/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Buni.h"

#include <QDebug>

Buni::Buni(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("buni");
}

QUrl Buni::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<div id=\"comic\">\n<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
