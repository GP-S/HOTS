#include "stdafx.h"
#include "Beast.h"
/* todo :
	attack() : 	- pas de gestion d'attaques multiples ou de modificateur d'attaque
				- pas de gestion de mort ici (a modifier ???)
				- on ne renvoit rien si on ne peut pas lancer attack() . 
					il faudrait un truc pour gérer ça . 
					ou gérer attackCount ailleurs . genre canAttack() ...




*/
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
    //dtor
}

bool Beast::isAlive(){
	return this->findByType(Att_vie)->getVal()>0;//je l'ai pas modifiée ne sachant pas trop comment ça allait se goupiller plus haut
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

void Beast::attack(Beast* target){//implémentation naive . a modifier .

	if(attackCount != 0){// pas de gestion de winfury pour le moment
		attackCount++;
		target.setHp(target.getHp()-attack);
		hp-=target.getAttack();
	}

}
