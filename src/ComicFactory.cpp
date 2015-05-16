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
#include "Comics/Fingerpori.h"
#include "Comics/FoxTrot.h"
#include "Comics/CyanideAndHappiness.h"
#include "Comics/HagarTheHorrible.h"
#include "Comics/Poyroot.h"
#include "Comics/ShitHappens.h"
#include "Comics/ViiviJaWagner.h"
#include "Comics/Smbc.h"
#include "Comics/PhdComics.h"
#include "Comics/FokIt.h"
#include "Comics/DieselSweeties.h"
#include "Comics/CommitStrip.h"
#include "Comics/TubeyToons.h"
#include "Comics/TheHatAndFat.h"
#include "Comics/TheAwkwardYeti.h"
#include "Comics/Lunarbaboon.h"
#include "Comics/SafelyEndangered.h"
#include "Comics/BerkeleyMews.h"

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

    if (id == "fingerpori")
        return new Fingerpori(parent);

    if (id == "foxtrot")
        return new FoxTrot(parent);

    if (id == "cyanideandhappiness")
        return new CyanideAndHappiness(parent);

    if (id == "hagarthehorrible")
        return new HagarTheHorrible(parent);

    if (id == "poyroot")
        return new Poyroot(parent);

    if (id == "shithappens")
        return new ShitHappens(parent);

    if (id == "viivijawagner")
        return new ViiviJaWagner(parent);

    if (id == "smbc")
        return new Smbc(parent);

    if (id == "phdcomics")
        return new PhdComics(parent);

    if (id == "fokit")
        return new FokIt(parent);

    if (id == "dieselsweeties")
        return new DieselSweeties(parent);

    if (id == "commitstrip")
        return new CommitStrip(parent);

    if (id == "tubeytoons")
        return new TubeyToons(parent);

    if (id == "thehatandfat")
        return new TheHatAndFat(parent);

    if (id == "theawkwardyeti")
        return new TheAwkwardYeti(parent);

    if (id == "lunarbaboon")
        return new Lunarbaboon(parent);

    if (id == "safelyendangered")
        return new SafelyEndangered(parent);

    if (id == "berkeleymews")
        return new BerkeleyMews(parent);

    return NULL;
}
