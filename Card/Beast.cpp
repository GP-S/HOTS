#include "Beast.h"

Beast::Beast()
{
  name = "unknown";
	hp = 0;
	baseAttack = 0;
}

Beast::Beast(string name,int hp, int attack) : 
{
	name = name;
	type = Card_crea;
	hp = hp;
	baseAttack = attack;
}


Beast::~Beast()
{
    
}

std::string Beast::getRace(){

	return race;
}

void Beast::setRace(std::string race){

	this->race=race;
}