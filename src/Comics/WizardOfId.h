/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#ifndef WIZARDOFID_H
#define WIZARDOFID_H

#include "../Comic.h"

class WizardOfId : public Comic
{
    Q_OBJECT

public:
    explicit WizardOfId(QObject *parent = 0);
    virtual QUrl extractStripImageUrl(QByteArray data);
};

#endif // WIZARDOFID_H
