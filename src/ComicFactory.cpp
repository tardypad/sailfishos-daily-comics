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
#include "Comics/Buni.h"
#include "Comics/NamelessPcs.h"

ComicFactory* ComicFactory::m_instance = NULL;

ComicFactory::ComicFactory(QObject *parent) :
    QObject(parent),
    m_map(QMap<QString, PCreateFunc>())
{
    registerComic<CalvinAndHobbes>("calvinandhobbes");
    registerComic<Dilbert>("dilbert");
    registerComic<Garfield>("garfield");
    registerComic<LeChat>("lechat");
    registerComic<Peanuts>("peanuts");
    registerComic<Xkcd>("xkcd");
    registerComic<DennisTheMenace>("dennisthemenace");
    registerComic<Fingerpori>("fingerpori");
    registerComic<FoxTrot>("foxtrot");
    registerComic<CyanideAndHappiness>("cyanideandhappiness");
    registerComic<HagarTheHorrible>("hagarthehorrible");
    registerComic<Poyroot>("poyroot");
    registerComic<ShitHappens>("shithappens");
    registerComic<ViiviJaWagner>("viivijawagner");
    registerComic<Smbc>("smbc");
    registerComic<PhdComics>("phdcomics");
    registerComic<FokIt>("fokit");
    registerComic<DieselSweeties>("dieselsweeties");
    registerComic<CommitStrip>("commitstrip");
    registerComic<TubeyToons>("tubeytoons");
    registerComic<TheHatAndFat>("thehatandfat");
    registerComic<TheAwkwardYeti>("theawkwardyeti");
    registerComic<Lunarbaboon>("lunarbaboon");
    registerComic<SafelyEndangered>("safelyendangered");
    registerComic<BerkeleyMews>("berkeleymews");
    registerComic<Buni>("buni");
    registerComic<NamelessPcs>("namelesspcs");
}

ComicFactory* ComicFactory::instance()
{
    if (!m_instance) {
        m_instance = new ComicFactory();
    }

    return m_instance;
}

Comic *ComicFactory::create(QString id, QObject *parent)
{
    QMap<QString, PCreateFunc>::iterator it = m_map.find(id);

    if (it == m_map.end())
        return NULL;

    PCreateFunc cf = it.value();
    return cf(parent);
}

QStringList ComicFactory::fullList() const
{
    return m_map.keys();
}
