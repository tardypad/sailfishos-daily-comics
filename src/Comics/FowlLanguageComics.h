/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef FOWLLANGUAGECOMICS_H
#define FOWLLANGUAGECOMICS_H

#include "../Comic.h"

class FowlLanguageComics : public Comic
{
    Q_OBJECT

public:
    explicit FowlLanguageComics(QString id, QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // FOWLLANGUAGECOMICS_H
