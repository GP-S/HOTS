#ifndef CREATEDECK_H
#define CREATEDECK_H

#include "../Card/Card.h"
#include "../Card/Beast.h"
#include "Spell.h"
#include "cstdlib"
#include "iostream"
#include "ctime"

int myRandom();

std::list<Card*>* newDeck();

#endif //CREATEDECK_H
