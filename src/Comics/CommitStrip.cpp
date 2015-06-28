/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "CommitStrip.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

CommitStrip::CommitStrip(QObject *parent) :
    Comic(parent)
{
}

const QString CommitStrip::_id                 = QString("commitstrip");
const QString CommitStrip::_name               = QString("CommitStrip");
const QColor CommitStrip::_color               = QColor(43, 63, 107);
const QStringList CommitStrip::_authors        = QStringList() << "Etienne Issartial" << "Thomas Gx";
const QUrl CommitStrip::_homepage              = QUrl("http://www.commitstrip.com/");
const QLocale::Country CommitStrip::_country   = QLocale::France;
const QLocale::Language CommitStrip::_language = QLocale::English;
const QDate CommitStrip::_startDate            = QDate::fromString("2012-02", "yyyy-MM");
const QDate CommitStrip::_endDate              = QDate::currentDate();
const QUrl CommitStrip::_stripSourceUrl        = QUrl("http://www.commitstrip.com/en/");

QUrl CommitStrip::extractStripImageUrl(QByteArray data)
{
    QString html(data);

    QRegularExpression reg("<img[^>]*src=\"([^\"]*/wp-content/uploads/[^\"]*)\"");
    QRegularExpressionMatch match = reg.match(html);

    if (!match.hasMatch()) {
        return QUrl();
    }

    QString src = match.captured(1);

    return QUrl(src);
}
