#ifndef CARD_TEST_H
#define CARD_TEST_H

/** 
*   File Test for Card
* @author Nicolas Léger
*
**/

#include "../../Card/Card.h"
#include "../../Card/Spell.h"
#include "../../Card/Creature.h"
#include "../../Card/Beast.h"
#include "../../Card/Capacity.h"
#include "../../Card/Hero.h"
#include "../../Effect/Effect.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <string>


void printEtape(std::string text);
void printBeast(Beast *beast);
void printHero(Hero *hero);
void printCreature(Creature *creature);
void printSpell(Spell *spell);
void printCard(Card *card);
void printIsAlive(Creature * creature);
void printAllCapa(Card *card);
void printEffect(Effect *effect);
void printCapacity(Capacity *capacity);
void printCapa(Card *card,std::string capaName,std::string name);

#endif //CARD_TEST_H