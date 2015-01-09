/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "LeChat.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

LeChat::LeChat(QObject *parent) :
    Comic(parent)
{
}

const QString LeChat::_id          = QString("lechat");
const QString LeChat::_name        = QString("Le Chat");
const QString LeChat::_author      = QString("Philippe Geluck");
const QUrl LeChat::_homepage       = QUrl("http://geluck.com/");
const QUrl LeChat::_stripSourceUrl = QUrl("http://geluck.com/dessin.html");

QUrl LeChat::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/strip/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl("http://geluck.com/" + src);
}
