#ifndef CREATURE_H
#define CREATURE_H

#include "stdafx.h"
#include "Card.h"


/** 
*   Class Creature . Derived from Card  .
* @author Armand
*
**/
/** @TODO :
*   attack() :  - attack modifiers are not handled yet
*               
*   canAttack() : - freeze, paralyze etc are not handled yet
*
*
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
        /**
        * takeDamage . Used everytime we need to damage a card . Does not handle things like divine shield yet .
        * @param unsigned int modifier The amount of the modification
        *
        **/
        void    takeDamage(unsigned int damage);
        /**
        * heal . Used everytime we need to heal a card
        * @param unsigned int modifier The amount of the modification
        *
        **/
        void    heal(unsigned int heal);
        /**
        * increaseMaxHP . Used everytime we need to increase the maximum HP of a card
        * @param unsigned int modifier The amount of the modification
        *
        **/
        void    increaseMaxHP(unsigned int modifier);
        /**
        * decreaseMaxHP . Used everytime we need to decrease the maximum HP of a card
        * @param unsigned int modifier The amount of the modification
        *
        **/
        void    decreaseMaxHP(unsigned int modifier);       
        /**
        * increaseAttackCount
        * Used every time a creature attacks .
        *
        **/
        void    increaseAttackCount(); 
    protected:

    private:
    	int hp;
    	int	attack;
    	int attackCount;
};

#endif // CREATURE_H
