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
	return this->findByType(Att_vie)->getVal()>0;//didn't modified this one because we don't have the architecture anyway 
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

void Beast::attack(Beast* target){//naive implemantation . modify this

	if(attackCount != 0){// windfury is not handled yet
		attackCount++;
		target.setHp(target.getHp()-attack);
		hp-=target.getAttack();
	}

}

void Beast::resetAttackCount(){// call this function on each beast when the turn begins

	attackCount=0;

}
