/**
 * Copyright (c) 2015 Damien Tardy-Panis
 *
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 **/

#include "ComicFactory.h"

#include "Comics/CalvinAndHobbes.h"
#include "Comics/Dilbert.h"
#include "Comics/Garfield.h"
#include "Comics/LeChat.h"
#include "Comics/Peanuts.h"
#include "Comics/Xkcd.h"
#include "Comics/DennisTheMenace.h"

Comic *ComicFactory::create(QString id, QObject *parent)
{
    if (id == "calvinandhobbes")
        return new CalvinAndHobbes(parent);

    if (id == "dilbert")
        return new Dilbert(parent);

    if (id == "garfield")
        return new Garfield(parent);

    if (id == "lechat")
        return new LeChat(parent);

    if (id == "peanuts")
        return new Peanuts(parent);

    if (id == "xkcd")
        return new Xkcd(parent);

    if (id == "dennisthemenace")
        return new DennisTheMenace(parent);

    return NULL;
}
