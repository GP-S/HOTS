#ifndef CREATEDECK_H
#define CREATEDECK_H

#include "../Card/Card.h"
#include "../Card/Beast.h"
#include "../Card/Spell.h"
#include "../Card/Capacity.h"
#include "../Effect/Effect.h"
#include "cstdlib"
#include "iostream"
#include "ctime"

int myRandom(unsigned int mod);

std::list<Card*>* newDeck();

#endif //CREATEDECK_H
