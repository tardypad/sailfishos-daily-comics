/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DinosaurComics.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

DinosaurComics::DinosaurComics(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("dinosaurcomics");
    m_info.name           = QString("Dinosaur Comics");
    m_info.color          = QColor(71, 144, 255);
    m_info.authors        = QStringList("Ryan North");
    m_info.homepage       = QUrl("http://www.qwantz.com/");
    m_info.country        = QLocale::Canada;
    m_info.language       = QLocale::English;
    m_info.startDate      = QDate::fromString("2003-02-01", Qt::ISODate);
    m_info.endDate        = QDate::currentDate();
    m_info.stripSourceUrl = QUrl("http://www.qwantz.com/index.php");
}

QUrl DinosaurComics::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*/comics/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
