#ifndef CREATEDECK_H
#define CREATEDECK_H

/** 
*   CreateDeck
* @author Nicolas Léger
*
**/

#include "../Card/Card.h"
#include "../Card/Beast.h"
#include "../Card/Spell.h"
#include "../Card/Hero.h"
#include "../Card/Capacity.h"
#include "../Effect/Effect.h"
#include "CreateCard.h"
#include "cstdlib"
#include "iostream"
#include "ctime"

/** 
*  just for get a random number
*
**/
int myRandom(unsigned int mod);

/** 
*  Create a full list of card.
*  Cards are beast or spell
*
**/
std::list<iCard*>* newDeck();

#endif //CREATEDECK_H
