
#include "Creature.h"

Creature::Creature()
{
    hp = 0;
    baseAttack = 0;
    attackCount = 0;
    name = "";
    cardType = "creature";
    capaList = new std::list<Capacity*>();
}

Creature::Creature(std::string name,int hp, int attack)  :
Card(name,  "creature")
{
    this->hp = hp;
    this->baseAttack = attack;
}


Creature::~Creature()
{
    
}
int Creature::getHp(){

    return hp;
}
int Creature::getBaseAttack(){

    return baseAttack;
}
void Creature::setHp(int hp){

    this->hp = hp;
}
void Creature::setBaseAttack(int attack){

    this->baseAttack = attack;
}


void Creature::resetAttackCount(){// call this function on each creature when the turn begins

    this->findCapaByType("attackCount")->front()->getEffect()->setValue(0);

}

bool Creature::canAttack(){

    return this->findCapaByType("attackCount")->front()->getEffect()->getValue()<this->findCapaByType("attackCountMax")->front()->getEffect()->getValue();

}

void Creature::increaseAttackCount(){

     this->findCapaByType("attackCount")->front()->getEffect()->setValue(this->findCapaByType("attackCount")->front()->getEffect()->getValue()+1);    
}


void Creature::takeDamage(unsigned int damage){

    std::list<Capacity*>* tempList = this->findCapaByType("hp");

     
    if (tempList->empty()){
        throw std::logic_error( "no hp capacity in current card" ); 
    }
 
    tempList->front()->getEffect()->setValue(tempList->front()->getEffect()->getValue()-damage);

}



void Creature::heal(unsigned int heal){

    std::list<Capacity*>* listHP = this->findCapaByType("hp");

     
    if (listHP->empty()){
        throw std::logic_error( "no hp capacity in current card" ); 
    }
 
    std::list<Capacity*>* listMaxHP = this->findCapaByType("hpMax");

     
    if (listMaxHP->empty()){
        throw std::logic_error( "no hp_max capacity in current card" ); 
    }

  int newhp=((listHP->front()->getEffect()->getValue()+heal>listMaxHP->front()->getEffect()->getValue())? listMaxHP->front()->getEffect()->getValue() :listHP->front()->getEffect()->getValue()+heal);
    listHP->front()->getEffect()->setValue(newhp);

}



void Creature::increaseMaxHP(unsigned int modifier){

    std::list<Capacity*>* listMaxHP = this->findCapaByType("hpMax");

     
    if (listMaxHP->empty()){
        throw std::logic_error( "no hp_max capacity in current card" ); 
    }

    listMaxHP->front()->getEffect()->setValue(listMaxHP->front()->getEffect()->getValue()+modifier);

}



void Creature::decreaseMaxHP(unsigned int modifier){

    std::list<Capacity*>* listMaxHP = this->findCapaByType("hpMax");

     
    if (listMaxHP->empty()){
        throw std::logic_error( "no hp_max capacity in current card" ); 
    }

    listMaxHP->front()->getEffect()->setValue(listMaxHP->front()->getEffect()->getValue()-modifier);

}


bool Creature::isAlive(){

     std::list<Capacity*>* listHP = this->findCapaByType("hp");

     
    if (listHP->empty()){
        throw std::logic_error( "no hp capacity in current card" ); 
    }

    return listHP->front()->getEffect()->getValue() > 0;
}