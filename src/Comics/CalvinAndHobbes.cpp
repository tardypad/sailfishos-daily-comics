/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "CalvinAndHobbes.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

CalvinAndHobbes::CalvinAndHobbes(QObject *parent) :
    Comic(parent)
{
}

const QString CalvinAndHobbes::_id          = QString("calvinandhobbes");
const QString CalvinAndHobbes::_name        = QString("Calvin and Hobbes");
const QString CalvinAndHobbes::_author      = QString("Bill Watterson");
const QUrl CalvinAndHobbes::_homepage       = QUrl("http://www.gocomics.com/calvinandhobbes/");
const QUrl CalvinAndHobbes::_stripSourceUrl = QUrl("http://www.gocomics.com/calvinandhobbes/");

QUrl CalvinAndHobbes::extractStripUrl(QByteArray data)
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
