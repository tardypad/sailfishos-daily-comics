/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "Peanuts.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

Peanuts::Peanuts(QObject *parent) :
    Comic(parent)
{
}

const QString Peanuts::_id          = QString("peanuts");
const QString Peanuts::_name        = QString("Peanuts");
const QString Peanuts::_author      = QString("Charles Monroe Schulz");
const QUrl Peanuts::_homepage       = QUrl("http://www.peanuts.com/");
const QUrl Peanuts::_stripSourceUrl = QUrl("http://www.peanuts.com/comics/");

QUrl Peanuts::extractStripUrl(QByteArray data)
{
    QString html(data);
    QRegularExpression reg("<img[^>]*src=\"(.*/comic-strip/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
