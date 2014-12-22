#ifndef HERO_H
#define HERO_H

#include <string>
#include <list>
#include <iostream>
#include "Creature.h"


/** 
*   Class Hero . Derived from Creature  .
* @author Armand
*
**/
/** @TODO :
*   
*   
*   
*   
*
*
**/
class Hero : public Creature
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

		
    protected:

    	
};

#endif // HERO_H
