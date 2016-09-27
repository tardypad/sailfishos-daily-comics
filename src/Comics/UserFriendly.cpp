/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "UserFriendly.h"

#include <QDebug>

UserFriendly::UserFriendly(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("userfriendly");
    m_info.name           = QString("User Friendly");
    m_info.color          = QColor(255, 255, 203);
    m_info.authors        = QStringList("J. D. Frazer \"Illiad\"");
    m_info.homepage       = QUrl("http://www.userfriendly.org");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.userfriendly.org/");
}

QUrl UserFriendly::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<IMG[^>]*SRC=\"([^\"]*/cartoons/archives/[^\"]*)\"");
}
