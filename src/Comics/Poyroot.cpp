/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Poyroot.h"

#include <QDebug>

Poyroot::Poyroot(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl Poyroot::extractStripImageUrl(QByteArray data)
{
    QUrl extractedStripImageUrl = regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/poyroot_[^\"]*)\"");

    if (extractedStripImageUrl.isValid()) {
        return extractedStripImageUrl;
    }

    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/Pöyrööt_[^\"]*)\"");
}
