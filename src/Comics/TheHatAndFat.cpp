/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TheHatAndFat.h"

#include <QDebug>

TheHatAndFat::TheHatAndFat(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("thehatandfat");
    m_info.name           = QString("The Hat and Fat");
    m_info.color          = QColor(50, 50, 50);
    m_info.authors        = QStringList() << "Eric Crowe" << "Dusty Perdue";
    m_info.homepage       = QUrl("https://thehatandfat.wordpress.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2013-02", "yyyy-MM");
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("https://thehatandfat.wordpress.com/");
}

QUrl TheHatAndFat::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(https://thehatandfat.files.wordpress.com/[^\"]*)\"");
}
