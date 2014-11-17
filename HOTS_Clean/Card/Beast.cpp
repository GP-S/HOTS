#include "stdafx.h"
#include "Beast.h"
/** @TODO :
*	attack() : 	- multiple attacks and attack modifiers are not handled yet
*				- death is not handled (need to modify ?)
*				- we don't send somehting when we cann't use attack() . 
*					need to modify this . 
*					or handle this elsewhere . like canAttack() ...
*
*
*
*
**/
Beast::Beast()
{
  name = "unknown";
	type = Card_crea;
	hp = 0;
	attack = 0;
}

Beast::Beast(string name,int hp, int attack)
{
	name = name;
	type = Card_crea;
	hp = hp;
	attack = attack;
}


Beast::~Beast()
{
    
}

bool Beast::isAlive(){
	return this->findCapaByType("hp")->getVal()>0;
}

int Beast::getHp(){

	return hp;
}
int Beast::getAttack(){

	return attack
}
void Beast::setHp(int hp){

	hp =hp;
}
void Beast::setAttack(int attack){

	attack=attack;
}

void Beast::attack(Beast* target){//this should work now .

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
		throw std::logic_error( "this beast can not attack now" ); 
	}
}

void Beast::resetAttackCount(){// call this function on each beast when the turn begins

	EffectCapacity attackCounter = new EffectCapacity();
	attackCount.resetAttackCount(this);

}
