/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "CommitStrip.h"

#include <QDebug>

CommitStrip::CommitStrip(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("commitstrip");
    m_info.name           = QString("CommitStrip");
    m_info.color          = QColor(42, 63, 106);
    m_info.authors        = QStringList() << "Etienne Issartial" << "Thomas Gx";
    m_info.homepage       = QUrl("http://www.commitstrip.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.commitstrip.com/en/feed/");
}

QUrl CommitStrip::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
