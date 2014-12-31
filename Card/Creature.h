#ifndef CREATURE_H
#define CREATURE_H


#include "Card.h"
#include "iCreature.h"
#include <string>
#include <list>
#include <iostream>



/** 
*   Class Creature . Derived from Card  .
* @author Armand
* @author Nicolas Léger
*
**/
/** @TODO :
*   attack() :  - attack modifiers are not handled yet
*               
*   canAttack() : - freeze, paralyze etc are not handled yet
*
*   vrais getters et setters des capacités 
*
**/
class Creature : public Card, virtual public iCreature
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
		Creature(std::string name,int hp,int attack);
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
		virtual bool isAlive();
        
        /**
        * getHp
        * Basic geter
        *
        **/
		virtual int getHp();
        /**
        * getAttack
        * Basic geter
        *
        **/
		virtual int getBaseAttack();
        /**
        * setHp
        * Basic seter
        *
        **/
		virtual void setHp(int hp);
        /**
        * setAttack
        * Basic seter
        *
        **/
		virtual void setBaseAttack(int attack);
        /**
        * resetAttackCount
        * Used everytime to reset the number of attacks a Creature did .
        *
        **/
        virtual void resetAttackCount();
        /**
        * canAttack
        * Tells if a creature can attack
        * @return a boolean that tells us if a creature can attack
        *
        **/
        virtual bool canAttack();
        /**
        * takeDamage . Used everytime we need to damage a card . Does not handle things like divine shield yet .
        * @param unsigned int modifier The amount of the modification
        *
        **/
        virtual void takeDamage(unsigned int damage);
        /**
        * heal . Used everytime we need to heal a card
        * @param unsigned int modifier The amount of the modification
        *
        **/
        virtual void heal(unsigned int heal);
        /**
        * increaseMaxHP . Used everytime we need to increase the maximum HP of a card
        * @param unsigned int modifier The amount of the modification
        *
        **/
        virtual void increaseMaxHP(unsigned int modifier);
        /**
        * decreaseMaxHP . Used everytime we need to decrease the maximum HP of a card
        * @param unsigned int modifier The amount of the modification
        *
        **/
        virtual void decreaseMaxHP(unsigned int modifier);       
        /**
        * increaseAttackCount
        * Used every time a creature attacks .
        *
        **/
        virtual void increaseAttackCount(); 

    protected:

    	int hp;
    	int	baseAttack;
    	int attackCount;
};

#endif // CREATURE_H
