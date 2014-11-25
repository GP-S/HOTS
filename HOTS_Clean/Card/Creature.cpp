#include "stdafx.h"
#include "Creature.h"
/** @TODO :
*   attack() :  - multiple attacks and attack modifiers are not handled yet
*               - death is not handled (need to modify ?)
*               - we don't send somehting when we cann't use attack() . 
*                   need to modify this . 
*                   or handle this elsewhere . like canAttack() ...
*
*
*
*
**/
Creature::Creature()
{
  name = "unknown";
    type = Card_crea;
    hp = 0;
    attack = 0;
}

Creature::Creature(string name,int hp, int attack)
{
    name = name;
    type = Card_crea;
    hp = hp;
    attack = attack;
}


Creature::~Creature()
{
    
}

bool Creature::isAlive(){
    return this->findCapaByType("hp")->getVal()>0;
}

int Creature::getHp(){

    return hp;
}
int Creature::getAttack(){

    return attack
}
void Creature::setHp(int hp){

    hp =hp;
}
void Creature::setAttack(int attack){

    attack=attack;
}

void Creature::attack(Creature* target){//this should work now .

    EffectCapacity attackCounter = new EffectCapacity();
    if(attackCounter.canAttack(this)){
        attackCount.increaseAttackCount(this);
        int attackerAttack = this->findCapaByType("attack").front.getVal();
        int defenderAttack = target->findCapaByType("attack").front.getVal();
        EffectLife damageAttacker = new EffectLife();
        EffectLife damageDefender = new EffectLife();
        damageDefender.takeDamage(target,attackerAttack);
        damageAttacker.takeDamage(this,defenderAttack);
    }
    else{
        throw std::logic_error( "this Creature can not attack now" ); 
    }
}

void Creature::resetAttackCount(){// call this function on each beast when the turn begins

    EffectCapacity attackCounter = new EffectCapacity();
    attackCount.resetAttackCount(this);

}
