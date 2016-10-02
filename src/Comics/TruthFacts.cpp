/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "TruthFacts.h"

#include <QDebug>

TruthFacts::TruthFacts(QString id, QObject *parent) :
    Comic(id, parent)
{
}

QUrl TruthFacts::extractStripImageUrl(QByteArray data)
{
    return regexExtractStripImageUrl(data, "<img[^>]*src=\"([^\"]*/img/truth_facts/[^\"]*)\"");
}
