/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheBoondocks.h"

#include <QDebug>

TheBoondocks::TheBoondocks(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl TheBoondocks::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
