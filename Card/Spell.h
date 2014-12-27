#ifndef SPELL_H
#define SPELL_H




#include "Card.h"
#include <string>
#include <list>
#include <iostream>



/** 
*   Class Spell . Derived from Card  .
* @author Armand
*
**/

class Spell : public Card
{
    public:
        /**
        * Default constructor
        * 
        *
        **/
                Spell();
        /**
        * Constructor
        * 
        *
        **/
                Spell(std::string name);
        /**
        * Destructor
        * Does nothing atm
        *
        **/
                ~Spell();
        
    protected:

        
};




#endif // SPELL_H
