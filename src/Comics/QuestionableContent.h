/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef QUESTIONABLECONTENT_H
#define QUESTIONABLECONTENT_H

#include "../Comic.h"

class QuestionableContent : public Comic
{
    Q_OBJECT

public:
    explicit QuestionableContent(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // QUESTIONABLECONTENT_H
