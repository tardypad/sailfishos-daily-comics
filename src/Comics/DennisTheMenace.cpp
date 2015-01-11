/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "DennisTheMenace.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

DennisTheMenace::DennisTheMenace(QObject *parent) :
    Comic(parent)
{
}

const QString DennisTheMenace::_id          = QString("dennisthemenace");
const QString DennisTheMenace::_name        = QString("Dennis The Menace");
const QString DennisTheMenace::_author      = QString("Hank Ketcham");
const QUrl DennisTheMenace::_homepage       = QUrl("http://dennisthemenace.com/");
const QUrl DennisTheMenace::_stripSourceUrl = QUrl("http://dennisthemenace.com/");

QUrl DennisTheMenace::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*content\\.php[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
