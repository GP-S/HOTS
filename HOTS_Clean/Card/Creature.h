#ifndef CREATURE_H
#define CREATURE_H

#include "stdafx.h"
#include "Card.h"


/** 
*   Class Creature . Derived from Card  .
* @author Armand
*
**/

abstract class Creature : public Card
{
    public:
        /**
        * Default constructor
        * 
        *
        **/
        		Creature();
        /**
        * Constructor
        * 
        *
        **/
				Creature(string name);
        /**
        * Destructor
        * Does nothing atm
        *
        **/
        		~Creature();
        /**
        * isAlive
        * @return a boolean corresponding to the state (dead or alive) of the Creature
        *
        **/
		bool 	isAlive();
        /**
        * getHp
        * Basic geter
        *
        **/
		int 	getHp();
        /**
        * getAttack
        * Basic geter
        *
        **/
		int 	getAttack();
        /**
        * setHp
        * Basic seter
        *
        **/
		void	setHp(int hp);
        /**
        * setAttack
        * Basic seter
        *
        **/
		void 	setAttack(int attack);
        /**
        * attack
        * Used to attack another Creature
        * @param Creature* target The target of the attack
        *
        *
        * modify it
        **/
		void 	attack(Creature* target);
        /**
        * resetAttackCount
        * Used every to reset the number of attacks a Creature did .
        *
        **/
        void    resetAttackCount();
    protected:

    private:
    	int hp;
    	int	attack;
    	int attackCount;
};

#endif // CREATURE_H
