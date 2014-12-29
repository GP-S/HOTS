#ifndef HERO_H
#define HERO_H

#include <string>
#include <list>
#include <iostream>
#include "Creature.h"
#include "iHero.h"


/** 
*   Class Hero . Derived from Creature  .
* @author Armand
* @author NicolasL
*
**/

class Hero : public Creature, public iHero
{
    public:
        /**
        * Default constructor
        * 
        *
        **/
        Hero();

        /**
        * Constructor
        * 
        *
        **/
		Hero(std::string name,int hp,int attack);

        /**
        * Destructor
        * Does nothing atm
        *
        **/
        ~Hero();

        /**
        * increaseShards . Used everytime we need to increase the shards of a hero
        * @param unsigned int modifier The amount of the modification
        *
        **/
        void    increaseShards(unsigned int modifier);
        /**
        * decreaseShards . Used everytime we need to decrease the shards of a hero
        * @param unsigned int modifier The amount of the modification
        *
        **/
        void    decreaseShards(unsigned int modifier);
        /**
        * increaseMaxShards . Used everytime we need to increase the maximum shards of a hero
        * @param unsigned int modifier The amount of the modification
        *
        **/
        void    increaseMaxShards(unsigned int modifier);
        /**
        * decreaseMaxShards . Used everytime we need to decrease the maximum shards of a hero
        * @param unsigned int modifier The amount of the modification
        *
        **/
        void    decreaseMaxShards(unsigned int modifier);

		
    protected:

    	
};

#endif // HERO_H
