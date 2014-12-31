#ifndef CREATEDECK_TEST_H
#define CREATEDECK_TEST_H

/** 
*   File Test for CreateDeck
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
#include "../../utils/CreateDeck.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <string>


void printBeast(Beast *beast);
void printSpell(Spell *spell);
void printCard(Card *card);
void printEffect(Card *card,std::string type);
void printEffect(Hero *hero);

#endif //CREATEDECK_TEST_H