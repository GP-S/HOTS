#ifndef CREATEDECK_H
#define CREATEDECK_H

#include "../Card/Card.h"
#include "../Card/Beast.h"
#include "../Card/Spell.h"
#include "../Card/Hero.h"
#include "../Card/Capacity.h"
#include "../Effect/Effect.h"
#include "cstdlib"
#include "iostream"
#include "ctime"

int myRandom(unsigned int mod);

Hero* newHero(std::string name);
std::list<iCard*>* newDeck();

#endif //CREATEDECK_H
