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

Comic *ComicFactory::create(QString id)
{
    if (id == "calvinandhobbes")
        return new CalvinAndHobbes();

    if (id == "dilbert")
        return new Dilbert();

    if (id == "garfield")
        return new Garfield();

    if (id == "lechat")
        return new LeChat();

    if (id == "peanuts")
        return new Peanuts();

    if (id == "xkcd")
        return new Xkcd();

    if (id == "dennisthemenace")
        return new DennisTheMenace();

    return NULL;
}
