#ifndef CREATEDECK_TEST_H
#define CREATEDECK_TEST_H

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

#include "../../utils/tool.inc"

void printBeast(Beast *beast,unsigned int max);
void printSpell(Spell *spell,unsigned int max);
void printCard(Card *card,unsigned int max);
void printEffect(Effect *effect,Card *card);

#endif //CREATEDECK_TEST_H