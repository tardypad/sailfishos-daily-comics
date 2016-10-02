/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Lwhag.h"

#include <QDebug>

Lwhag::Lwhag(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl Lwhag::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*)\"[^>]*alt=\"[^\"]*english\"");
}
