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
#include "Comics/Pigknit.h"
#include "Comics/SadSacks.h"
#include "Comics/FowlLanguageComics.h"
#include "Comics/PirateMike.h"
#include "Comics/Yodablog.h"
#include "Comics/WhatAWonderfulWorld.h"
#include "Comics/LupoAlberto.h"
#include "Comics/RabbitualOffender.h"
#include "Comics/FredBasset.h"
#include "Comics/Sigmund.h"
#include "Comics/MacadamValley.h"
#include "Comics/LoadingArtist.h"
#include "Comics/CheerUpEmoKid.h"
#include "Comics/ExtraOrdinary.h"
#include "Comics/DinosaurComics.h"
#include "Comics/FokkeEnSukke.h"
#include "Comics/PBFComics.h"
#include "Comics/Ahistaa.h"
#include "Comics/BloomCounty2015.h"
#include "Comics/DarthsAndDroids.h"
#include "Comics/Dirkjan.h"
#include "Comics/Erzaehlmirnix.h"
#include "Comics/FMinus.h"
#include "Comics/IsLieb.h"
#include "Comics/Nichtlustig.h"
#include "Comics/PoorlyDrawnLines.h"
#include "Comics/SarahsScribbles.h"
#include "Comics/SavageChickens.h"
#include "Comics/Sinfest.h"
#include "Comics/TheBoondocks.h"
#include "Comics/TheVeryNearFuture.h"
#include "Comics/ThingsInSquares.h"
#include "Comics/WizardOfId.h"
#include "Comics/BashIm.h"
#include "Comics/IntrovertDoodles.h"
#include "Comics/Swamp.h"
#include "Comics/TheGamerCat.h"
#include "Comics/TheWhiteboard.h"
#include "Comics/AndyCapp.h"
#include "Comics/BeetleBailey.h"
#include "Comics/DrMcNinja.h"
#include "Comics/Einbilder.h"
#include "Comics/LizClimo.h"
#include "Comics/NedroidPictureDiary.h"
#include "Comics/OctopusPie.h"
#include "Comics/QuestionableContent.h"
#include "Comics/Gwtb.h"
#include "Comics/Lwhag.h"
#include "Comics/PearlsBeforeSwine.h"
#include "Comics/DerFlix.h"
#include "Comics/WrongHands.h"
#include "Comics/JaatavaSpede.h"
#include "Comics/Lunch.h"
#include "Comics/AnonyymitElaimet.h"

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
    registerComic<Pigknit>("pigknit");
    registerComic<SadSacks>("sadsacks");
    registerComic<FowlLanguageComics>("fowllanguagecomics");
    registerComic<PirateMike>("piratemike");
    registerComic<Yodablog>("yodablog");
    registerComic<WhatAWonderfulWorld>("whatawonderfulworld");
    registerComic<LupoAlberto>("lupoalberto");
    registerComic<RabbitualOffender>("rabbitualoffender");
    registerComic<FredBasset>("fredbasset");
    registerComic<Sigmund>("sigmund");
    registerComic<MacadamValley>("macadamvalley");
    registerComic<LoadingArtist>("loadingartist");
    registerComic<CheerUpEmoKid>("cheerupemokid");
    registerComic<ExtraOrdinary>("extraordinary");
    registerComic<DinosaurComics>("dinosaurcomics");
    registerComic<FokkeEnSukke>("fokkeensukke");
    registerComic<PBFComics>("pbfcomics");
    registerComic<Ahistaa>("ahistaa");
    registerComic<BloomCounty2015>("bloomcounty2015");
    registerComic<DarthsAndDroids>("darthsanddroids");
    registerComic<Dirkjan>("dirkjan");
    registerComic<Erzaehlmirnix>("erzaehlmirnix");
    registerComic<FMinus>("fminus");
    registerComic<IsLieb>("islieb");
    registerComic<Nichtlustig>("nichtlustig");
    registerComic<PoorlyDrawnLines>("poorlydrawnlines");
    registerComic<SarahsScribbles>("sarahsscribbles");
    registerComic<SavageChickens>("savagechickens");
    registerComic<Sinfest>("sinfest");
    registerComic<TheBoondocks>("theboondocks");
    registerComic<TheVeryNearFuture>("theverynearfuture");
    registerComic<ThingsInSquares>("thingsinsquares");
    registerComic<WizardOfId>("wizardofid");
    registerComic<BashIm>("bashim");
    registerComic<IntrovertDoodles>("introvertdoodles");
    registerComic<Swamp>("swamp");
    registerComic<TheGamerCat>("thegamercat");
    registerComic<TheWhiteboard>("thewhiteboard");
    registerComic<AndyCapp>("andycapp");
    registerComic<BeetleBailey>("beetlebailey");
    registerComic<DrMcNinja>("drmcninja");
    registerComic<Einbilder>("einbilder");
    registerComic<LizClimo>("lizclimo");
    registerComic<NedroidPictureDiary>("nedroidpicturediary");
    registerComic<OctopusPie>("octopuspie");
    registerComic<QuestionableContent>("questionablecontent");
    registerComic<Gwtb>("gwtb");
    registerComic<Lwhag>("lwhag");
    registerComic<PearlsBeforeSwine>("pearlsbeforeswine");
    registerComic<DerFlix>("derflix");
    registerComic<WrongHands>("wronghands");
    registerComic<JaatavaSpede>("jaatavaspede");
    registerComic<Lunch>("lunch");
    registerComic<AnonyymitElaimet>("anonyymitelaimet");
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
