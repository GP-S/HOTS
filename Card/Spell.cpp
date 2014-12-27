#include "Spell.h"

Spell::Spell()
{
    name = "unknown";
    
}

Spell::Spell(std::string name)  :
Card(name,  "Spell")
{
 
}


Spell::~Spell()
{
    
}