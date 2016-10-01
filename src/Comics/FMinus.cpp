/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FMinus.h"

#include <QDebug>

FMinus::FMinus(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("fminus");
}

QUrl FMinus::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
