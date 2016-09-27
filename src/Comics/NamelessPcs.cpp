/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "NamelessPcs.h"

#include <QDebug>

NamelessPcs::NamelessPcs(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("namelesspcs");
    m_info.name           = QString("Nameless PCs");
    m_info.color          = QColor(116, 209, 240);
    m_info.authors        = QStringList("Wesley Hall");
    m_info.homepage       = QUrl("http://namelesspcs.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://namelesspcs.com/");
}

QUrl NamelessPcs::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
