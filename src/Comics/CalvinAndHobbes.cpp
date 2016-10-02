/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "CalvinAndHobbes.h"

#include <QDebug>

CalvinAndHobbes::CalvinAndHobbes(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl CalvinAndHobbes::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
