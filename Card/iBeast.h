#ifndef IBEAST_H
#define IBEAST_H

#include "iCreature.h"

/** 
*   Class iBeast . derived from iCreature
* @author Armand
*
**/

class iBeast : virtual public iCreature
{
    public:


        /**
        * getRace
        * Basic geter
        *
        **/
		virtual std::string getRace() = 0;
        
        /**
        * setRace
        * Basic seter
        *
        **/
		virtual void setRace(std::string race) = 0;


};

#endif // IBEAST_H