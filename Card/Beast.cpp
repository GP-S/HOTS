#include "Beast.h"

Beast::Beast() :
Creature()
{
	race = "";
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