/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "WizardOfId.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

WizardOfId::WizardOfId(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("wizardofid");
    m_info.name           = QString("Wizard of Id");
    m_info.color          = QColor(210, 45, 43);
    m_info.authors        = QStringList() <<  "Brant Parker" << "Johnny Hart";
    m_info.homepage       = QUrl("http://www.gocomics.com/wizardofid");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("1964-11-09", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.gocomics.com/wizardofid");
}

QUrl WizardOfId::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*class=\"strip\".*src=\"([^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
