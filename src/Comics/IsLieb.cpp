/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "IsLieb.h"

#include <QDebug>

IsLieb::IsLieb(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("islieb");
}

QUrl IsLieb::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
