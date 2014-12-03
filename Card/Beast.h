#ifndef BEAST_H
#define BEAST_H

#include <string>
#include <list>
#include <iostream>
#include "Creature.h"


/** 
*   Class Beast . Derived from Creature  .
* @author Armand
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
class Beast : public Creature
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
				Beast(std::string race);
        /**
        * Destructor
        * Does nothing atm
        *
        **/
        	   	           ~Beast();
        /**
        * isAlive
        * @return a boolean corresponding to the state (dead or alive) of the beast
        *
        **/
		bool 	            isAlive();
        /**
        * getRace
        * Basic geter
        *
        **/
		std::string       getRace();
        /**
        * setRace
        * Basic seter
        *
        **/
		void	          setRace(std::string race);

		
    protected:

    	std::string race;
};

#endif // BEAST_H
