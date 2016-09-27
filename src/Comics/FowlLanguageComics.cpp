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
    m_info.id             = QString("fowllanguagecomics");
    m_info.name           = QString("Fowl Language Comics");
    m_info.color          = QColor(219, 232, 212);
    m_info.authors        = QStringList("Brian Gordon");
    m_info.homepage       = QUrl("http://www.fowllanguagecomics.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.fowllanguagecomics.com");
}

QUrl FowlLanguageComics::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<meta property=\"og:image\" content=\"([^\"]*)\"");
}
