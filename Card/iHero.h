#ifndef IHERO_H
#define IHERO_H

#include "iCreature.h"

/** 
*   Class iHero . Derived from iCreature  .
* @author Armand
*
**/

class iHero : virtual public iCreature
{
    public:

        /**
        * increaseShards . Used everytime we need to increase the shards of a hero
        * @param unsigned int modifier The amount of the modification
        *
        **/
        virtual void    increaseShards(unsigned int modifier) = 0;
        /**
        * decreaseShards . Used everytime we need to decrease the shards of a hero
        * @param unsigned int modifier The amount of the modification
        *
        **/
        virtual void    decreaseShards(unsigned int modifier) = 0;

        virtual void    setShards(unsigned int newShards) = 0;
        /**
        * increaseMaxShards . Used everytime we need to increase the maximum shards of a hero
        * @param unsigned int modifier The amount of the modification
        *
        **/
        virtual void    increaseMaxShards(unsigned int modifier) = 0;
        /**
        * decreaseMaxShards . Used everytime we need to decrease the maximum shards of a hero
        * @param unsigned int modifier The amount of the modification
        *
        **/
        virtual void    decreaseMaxShards(unsigned int modifier) = 0;

        virtual void    setMaxShards(unsigned int newMaxShards) = 0;

		    	
};

#endif // IHERO_H
