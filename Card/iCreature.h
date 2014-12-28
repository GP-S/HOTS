#ifndef ICREATURE_H
#define ICREATURE_H

/** 
*   Class iCreature . 
* @author Armand
*
**/

class iCreature
{
    public:
        

        /**
        * isAlive
        * @return a boolean corresponding to the state (dead or alive) of the Creature
        *
        **/
		virtual bool 	isAlive() = 0;
        
        /**
        * getHp
        * Basic geter
        *
        **/
		virtual int 	getHp() = 0;
        /**
        * getAttack
        * Basic geter
        *
        **/
		virtual int 	getBaseAttack() = 0;
        /**
        * setHp
        * Basic seter
        *
        **/
		virtual void	setHp(int hp) = 0;
        /**
        * setAttack
        * Basic seter
        *
        **/
		virtual void 	setBaseAttack(int attack) = 0;
        /**
        * attack
        * Used to attack another Creature
        * @param Creature* target The target of the attack
        *
        *
        * modify it
        **/
		virtual void 	attack(iCreature* target) = 0;
        /**
        * resetAttackCount
        * Used every to reset the number of attacks a Creature did .
        *
        **/
        virtual void    resetAttackCount() = 0;
        /**
        * canAttack
        * Tells if a creature can attack
        * @return a boolean that tells us if a creature can attack
        *
        **/
        virtual bool canAttack() = 0;
        /**
        * takeDamage . Used everytime we need to damage a card . Does not handle things like divine shield yet .
        * @param unsigned int modifier The amount of the modification
        *
        **/
        virtual void    takeDamage(unsigned int damage) = 0;
        /**
        * heal . Used everytime we need to heal a card
        * @param unsigned int modifier The amount of the modification
        *
        **/
        virtual void    heal(unsigned int heal) = 0;
        /**
        * increaseMaxHP . Used everytime we need to increase the maximum HP of a card
        * @param unsigned int modifier The amount of the modification
        *
        **/
        virtual void    increaseMaxHP(unsigned int modifier) = 0;
        /**
        * decreaseMaxHP . Used everytime we need to decrease the maximum HP of a card
        * @param unsigned int modifier The amount of the modification
        *
        **/
        virtual void    decreaseMaxHP(unsigned int modifier)= 0 ;
        /**
        * increaseAttackCount
        * Used every time a creature attacks .
        *
        **/
        virtual void    increaseAttackCount() = 0 ;

};

#endif // ICREATURE_H
