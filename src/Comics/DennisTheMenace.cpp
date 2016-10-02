/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DennisTheMenace.h"

#include <QDebug>

DennisTheMenace::DennisTheMenace(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl DennisTheMenace::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<meta property=\"og:image\" content=\"([^\"]*)\"");
}
