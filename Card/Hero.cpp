#include "Hero.h"

Hero::Hero()
{
  name = "unknown";
    hp = 0;
    baseAttack = 0;
}

Hero::Hero(std::string name,int hp,int attack) :
Creature(name,hp,attack)
{
   
}


Hero::~Hero()
{
    
}

