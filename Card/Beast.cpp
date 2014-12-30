#include "Beast.h"

Beast::Beast()
{
	race = "";
	hp = 0;
    baseAttack = 0;
    attackCount = 0;
	name = "";
	cardType = "beast";
	capaList = new std::list<Capacity*>();
}

Beast::Beast(std::string name,int hp,int attack,std::string race) :
Creature(name,hp,attack)
{
	this->race = race;
	setType("beast");
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