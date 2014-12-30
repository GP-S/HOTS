#ifndef BEAST_H
#define BEAST_H

#include <string>
#include <list>
#include <iostream>
#include "Creature.h"
#include "iBeast.h"


/** 
*   Class Beast . Derived from Creature  .
* @author Armand
* @author NicolasL
*
**/
/** @TODO :
*   
*   
*   
*   add what specifies a Beast (owner ?)
*
*
**/
class Beast : public Creature, virtual public iBeast
{
    public:
        /**
        * Default constructor
        * 
        *
        **/
        Beast();

        /**
        * Constructor
        * 
        *
        **/
		Beast(std::string name,int hp,int attack,std::string race);

        /**
        * Destructor
        * Does nothing atm
        *
        **/
        ~Beast();

        /**
        * getRace
        * Basic geter
        *
        **/
		std::string getRace();
        
        /**
        * setRace
        * Basic seter
        *
        **/
		void setRace(std::string race);

		
    protected:

    	std::string race;
};

#endif // BEAST_H
