/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "WhatAWonderfulWorld.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

WhatAWonderfulWorld::WhatAWonderfulWorld(QObject *parent) :
    Comic(parent)
{
}

const QString WhatAWonderfulWorld::_id                 = QString("whatawonderfulworld");
const QString WhatAWonderfulWorld::_name               = QString("What a wonderful world!");
const QColor WhatAWonderfulWorld::_color               = QColor(195, 143, 189);
const QStringList WhatAWonderfulWorld::_authors        = QStringList("Philippe Chappuis \"Zep\"");
const QUrl WhatAWonderfulWorld::_homepage              = QUrl("http://zepworld.blog.lemonde.fr/");
const QLocale::Country WhatAWonderfulWorld::_country   = QLocale::Switzerland;
const QLocale::Language WhatAWonderfulWorld::_language = QLocale::French;
const QDate WhatAWonderfulWorld::_startDate            = QDate::fromString("2014-11-01", Qt::ISODate);
const QDate WhatAWonderfulWorld::_endDate              = QDate::currentDate();
const QUrl WhatAWonderfulWorld::_stripSourceUrl        = QUrl("http://zepworld.blog.lemonde.fr/feed/atom/");

QUrl WhatAWonderfulWorld::extractStripImageUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"([^\"]*/files/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
