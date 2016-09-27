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
    m_info.id             = QString("fminus");
    m_info.name           = QString("F Minus");
    m_info.color          = QColor(158, 44, 34);
    m_info.authors        = QStringList("Tony Carrillo");
    m_info.homepage       = QUrl("http://www.fminus.net/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/fminus");
}

QUrl FMinus::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
