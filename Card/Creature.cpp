
#include "Creature.h"

Creature::Creature()
{
    name = "unknown";
    hp = 0;
    baseAttack = 0;
}

Creature::Creature(std::string name,int hp, int attack)
{
    name = name;
    hp = hp;
    baseAttack = attack;
}


Creature::~Creature()
{
    
}
/* 
bool Creature::isAlive(){
    return this->findCapaByType("hp")->front()->getEffect()->getValue()>0;
}
*/
int Creature::getHp(){

    return hp;
}
int Creature::getBaseAttack(){

    return baseAttack;
}
void Creature::setHp(int hp){

    hp =hp;
}
void Creature::setBaseAttack(int attack){

    baseAttack=attack;
}

void Creature::attack(Creature* target){//this should work now 

   /* 
    if(this->canAttack()){
        this->increaseAttackCount();
        int attackerAttack ;
        std::list<Capacity*>* capaListTemp = this->findCapaByType("attack");
        Capacity* capaAttack = capaListTemp->front();
        attackerAttack=canAttack.getEffect()->getValue();
        int defenderAttack = target->findCapaByType("attack")->front()->getEffect()->getValue();
        target->takeDamage(attackerAttack);
        this->takeDamage(defenderAttack);
    }
    else{
        throw std::logic_error( "this Creature can not attack now" ); 
    }*/
}

void Creature::resetAttackCount(){// call this function on each creature when the turn begins

    this->findCapaByType("AttackCount")->front()->getEffect()->setValue(0);

}

bool Creature::canAttack(){

    return this->findCapaByType("AttackCount")->front()->getEffect()->getValue()<this->findCapaByType("AttackCountMax")->front()->getEffect()->getValue();

}

void Creature::increaseAttackCount(){

     this->findCapaByType("AttackCount")->front()->getEffect()->setValue(this->findCapaByType("AttackCount")->front()->getEffect()->getValue()+1);    
}


void Creature::takeDamage(unsigned int damage){

    std::string capaType = "hp";
    std::list<Capacity*>* tempList = this->findCapaByType(capaType);

     
        if (tempList->empty()){
    throw std::logic_error( "no hp capacity in current card" ); 
    }
 
    tempList->front()->getEffect()->setValue(tempList->front()->getEffect()->getValue()-damage);

}



void Creature::heal(unsigned int heal){

    std::string hp = "hp";
    std::list<Capacity*>* listHP = this->findCapaByType(hp);

     
        if (listHP->empty()){
    throw std::logic_error( "no hp capacity in current card" ); 
    }
 
    std::string maxHP = "max_hp";
    std::list<Capacity*>* listMaxHP = this->findCapaByType(maxHP);

     
        if (listMaxHP->empty()){
    throw std::logic_error( "no hp_max capacity in current card" ); 
    }

  int newhp=((listHP->front()->getEffect()->getValue()+heal>listMaxHP->front()->getEffect()->getValue())? listMaxHP->front()->getEffect()->getValue() :listHP->front()->getEffect()->getValue()+heal);
    listHP->front()->getEffect()->setValue(newhp);

}



void Creature::increaseMaxHP(unsigned int modifier){

    std::string maxHP = "max_hp";
    std::list<Capacity*>* listMaxHP = this->findCapaByType(maxHP);

     
        if (listMaxHP->empty()){
    throw std::logic_error( "no hp_max capacity in current card" ); 
    }

    listMaxHP->front()->getEffect()->setValue(listMaxHP->front()->getEffect()->getValue()+modifier);

}



void Creature::decreaseMaxHP(unsigned int modifier){

    std::string maxHP = "max_hp";
    std::list<Capacity*>* listMaxHP = this->findCapaByType(maxHP);

     
        if (listMaxHP->empty()){
    throw std::logic_error( "no hp_max capacity in current card" ); 
    }

    listMaxHP->front()->getEffect()->setValue(listMaxHP->front()->getEffect()->getValue()-modifier);

}
