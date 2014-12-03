#ifndef CREATURE_H
#define CREATURE_H


#include "Card.h"
#include <string>
#include <list>
#include <iostream>


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
class Creature : public Card
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
				Creature(std::string name);
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
		virtual bool 	isAlive();
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
		int 	getBaseAttack();
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
		void 	setBaseAttack(int attack);
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

    	int hp;
    	int	baseAttack;
    	int attackCount;
};

#endif // CREATURE_H
