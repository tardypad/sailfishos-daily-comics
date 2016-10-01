/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Poyroot.h"

#include <QDebug>

Poyroot::Poyroot(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("poyroot");
}

QUrl Poyroot::extractStripImageUrl(QByteArray data)
{
    QUrl extractedStripImageUrl = regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/poyroot_[^\"]*)\"");

    if (extractedStripImageUrl.isValid()) {
        return extractedStripImageUrl;
    }

    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/Pöyrööt_[^\"]*)\"");
}
