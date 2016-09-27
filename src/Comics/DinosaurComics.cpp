/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DinosaurComics.h"

#include <QDebug>

DinosaurComics::DinosaurComics(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("dinosaurcomics");
    m_info.name           = QString("Dinosaur Comics");
    m_info.color          = QColor(71, 144, 255);
    m_info.authors        = QStringList("Ryan North");
    m_info.homepage       = QUrl("http://www.qwantz.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.qwantz.com/index.php");
}

QUrl DinosaurComics::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/comics/[^\"]*)\"");
}
