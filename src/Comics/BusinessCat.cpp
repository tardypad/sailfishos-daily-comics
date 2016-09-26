/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "BusinessCat.h"

#include <QDebug>

BusinessCat::BusinessCat(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("businesscat");
    m_info.name           = QString("The Adventures of Business Cat");
    m_info.color          = QColor(120, 138, 188);
    m_info.authors        = QStringList("Tom Fonder");
    m_info.homepage       = QUrl("http://www.businesscat.happyjar.com/");
    m_info.country        = QLocale::UnitedKingdom;
    m_info.language       = QLocale::English;
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.businesscat.happyjar.com/");
}

QUrl BusinessCat::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
