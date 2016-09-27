/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DieselSweeties.h"

#include <QDebug>

DieselSweeties::DieselSweeties(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("dieselsweeties");
    m_info.name           = QString("Diesel Sweeties");
    m_info.color          = QColor(117, 141, 67);
    m_info.authors        = QStringList("Richard Stevens III");
    m_info.homepage       = QUrl("http://dieselsweeties.com/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.dieselsweeties.com/ds-unifeed.xml");
}

QUrl DieselSweeties::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/strips[^\"]*)\"");
}
