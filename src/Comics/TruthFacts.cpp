/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TruthFacts.h"

#include <QDebug>

TruthFacts::TruthFacts(QObject *parent) :
    Comic(parent)
{
    m_info.id             = QString("truthfacts");
    m_info.name           = QString("Truth Facts");
    m_info.color          = QColor(255, 150, 0);
    m_info.authors        = QStringList() << "Mikael Wulff" << "Anders Morgenthaler";
    m_info.homepage       = QUrl("http://truthfacts.com/");
    m_info.language       = QLocale::English;
    m_info.stripSourceUrl = QUrl("http://truthfacts.com/truthfacts?view=rss");
}

QUrl TruthFacts::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/img/truth_facts/[^\"]*)\"");
}
