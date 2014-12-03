#include "Card.h"

Card::Card(){
	strength = 0;
	life = 0;
}
	

Card::Card(int strength,int life){

	this->strength = strength;
	this->life = life;
}

int Card::getStrength(){

	return strength;
}

int Card::getLife(){

	return life;
}

void Card::setStrength(int strength){
	this->strength = strength;
}

void Card::setLife(int life){
	this->life = life;
}
