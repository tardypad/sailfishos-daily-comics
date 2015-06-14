/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "FowlLanguageComics.h"

#include <QDebug>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

FowlLanguageComics::FowlLanguageComics(QObject *parent) :
    Comic(parent)
{
}

const QString FowlLanguageComics::_id                 = QString("fowllanguagecomics");
const QString FowlLanguageComics::_name               = QString("Fowl Language Comics");
const QColor FowlLanguageComics::_color               = QColor(154, 208, 244);
const QStringList FowlLanguageComics::_authors        = QStringList("Brian Gordon");
const QUrl FowlLanguageComics::_homepage              = QUrl("http://www.fowllanguagecomics.com/");
const QLocale::Country FowlLanguageComics::_country   = QLocale::UnitedStates;
const QLocale::Language FowlLanguageComics::_language = QLocale::English;
const QDate FowlLanguageComics::_startDate            = QDate::fromString("2013-07-22", Qt::ISODate);
const QDate FowlLanguageComics::_endDate              = QDate::currentDate();
const QUrl FowlLanguageComics::_stripSourceUrl        = QUrl("http://www.fowllanguagecomics.com/");

QUrl FowlLanguageComics::extractStripUrl(QByteArray data)
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
