#include "Beast.h"

Beast::Beast()
{
  name = "unknown";
	hp = 0;
	baseAttack = 0;
	race = "";
}

Beast::Beast(std::string race)
{
	race=race;
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