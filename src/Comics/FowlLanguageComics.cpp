/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FowlLanguageComics.h"

#include <QDebug>

FowlLanguageComics::FowlLanguageComics(QObject *parent) :
    Comic(parent)
{
    m_info.id = QString("fowllanguagecomics");
}

QUrl FowlLanguageComics::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<meta property=\"og:image\" content=\"([^\"]*)\"");
}
