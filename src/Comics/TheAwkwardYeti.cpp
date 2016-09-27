/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheAwkwardYeti.h"

#include <QDebug>

TheAwkwardYeti::TheAwkwardYeti(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("theawkwardyeti");
    m_info.name           = QString("The Awkward Yeti");
    m_info.color          = QColor(255, 200, 47);
    m_info.authors        = QStringList("Nick Seluk");
    m_info.homepage       = QUrl("http://theawkwardyeti.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://theawkwardyeti.com/");
}

QUrl TheAwkwardYeti::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<div id=\"comic\">\\s*<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
