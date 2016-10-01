/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheAwkwardYeti.h"

#include <QDebug>

TheAwkwardYeti::TheAwkwardYeti(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("theawkwardyeti");
}

QUrl TheAwkwardYeti::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<div id=\"comic\">\\s*<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
