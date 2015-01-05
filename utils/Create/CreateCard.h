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
#include "cstdlib"
#include "iostream"
#include "ctime"

/** 
*  Create a new Beast object.
*
**/
Beast* newBeast(std::string name = "",int hp = 0,int attack = 0,std::string race = "");

/** 
*  Create a new Spell object.
*
**/
Spell* newBeast(std::string name = "",int damage = 0);

/** 
*  Create a new Hero object.
*
**/
Hero* newHero(std::string name = "",int hp = 0);

#endif //CREATEDECK_H
