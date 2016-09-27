/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Sigmund.h"

#include <QDebug>

Sigmund::Sigmund(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("sigmund");
    m_info.name           = QString("Sigmund");
    m_info.color          = QColor(255, 255, 169);
    m_info.authors        = QStringList("Peter de Wit");
    m_info.homepage       = QUrl("http://www.sigmund.nl/");
    m_info.language       = QLocale::Dutch;
    m_info.stripSourceUrl = QUrl("http://www.sigmund.nl/?p=home");
}

QUrl Sigmund::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=(strips/[^ ]*) ");
}
