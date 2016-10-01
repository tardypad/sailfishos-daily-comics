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
    m_info.id = QString("userfriendly");
}

QUrl UserFriendly::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<IMG[^>]*SRC=\"([^\"]*/cartoons/archives/[^\"]*)\"");
}
