/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "IntrovertDoodles.h"

#include <QDebug>

IntrovertDoodles::IntrovertDoodles(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("introvertdoodles");
    m_info.name           = QString("Introvert Doodles");
    m_info.color          = QColor(226, 28, 77);
    m_info.authors        = QStringList("Marzi");
    m_info.homepage       = QUrl("http://introvertdoodles.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://introvertdoodles.com/");
}

QUrl IntrovertDoodles::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
}
