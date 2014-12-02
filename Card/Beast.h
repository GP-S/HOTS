#ifndef BEAST_H
#define BEAST_H

#include "stdafx.h"
#include "Creature.h"


/** 
*   Class Beast . Derived from Creature  .
* @author Armand
*
**/
/** @TODO :
*   
*   remove the methods that are in Creature .             
*   remove the attributes that are in Creature .
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
				Beast(string name);
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
        * Used to attack another beast
        * @param Beast* target The target of the attack
        *
        *
        * modify it
        **/
		void 	attack(Creature* target);
        /**
        * resetAttackCount
        * Used every to reset the number of attacks a beast did .
        *
        **/
        void    resetAttackCount();
    protected:

    private:
    	int hp;
    	int	attack;
    	int attackCount;
};

#endif // BEAST_H
