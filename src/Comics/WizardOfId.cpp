/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "WizardOfId.h"

#include <QDebug>

WizardOfId::WizardOfId(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("wizardofid");
    m_info.name           = QString("Wizard of Id");
    m_info.color          = QColor(210, 45, 43);
    m_info.authors        = QStringList() <<  "Brant Parker" << "Johnny Hart";
    m_info.homepage       = QUrl("http://www.gocomics.com/wizardofid");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/wizardofid");
}

QUrl WizardOfId::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
}
