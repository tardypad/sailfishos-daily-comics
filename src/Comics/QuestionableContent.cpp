/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "QuestionableContent.h"

#include <QDebug>

QuestionableContent::QuestionableContent(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("questionablecontent");
    m_info.name           = QString("Questionable Content");
    m_info.color          = QColor(118, 161, 178);
    m_info.authors        = QStringList("Jeph Jacques");
    m_info.homepage       = QUrl("http://questionablecontent.net/");
    m_info.country        = QLocale::UnitedStates;
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://www.questionablecontent.net/QCRSS.xml");
}

QUrl QuestionableContent::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"(.*/comics/[^\"]*)\"");
}
