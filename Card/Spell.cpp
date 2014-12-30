#include "Spell.h"

Spell::Spell()
{
	name = "";
	cardType = "spell";
	capaList = new std::list<Capacity*>();
}

Spell::Spell(std::string name)  :
Card(name,  "spell")
{
 
}


Spell::~Spell()
{
    
}