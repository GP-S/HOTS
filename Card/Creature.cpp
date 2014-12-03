
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
    return this->findCapaByType("hp")->front()->getVal()>0;
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
        attackerAttack=canAttack.getVal();
        int defenderAttack = target->findCapaByType("attack")->front()->getVal();
        target->takeDamage(attackerAttack);
        this->takeDamage(defenderAttack);
    }
    else{
        throw std::logic_error( "this Creature can not attack now" ); 
    }*/
}

void Creature::resetAttackCount(){// call this function on each creature when the turn begins

    this->findCapaByType("AttackCount")->front()->setVal(0);

}

bool Creature::canAttack(){

    return this->findCapaByType("AttackCount")->front()->getVal()<this->findCapaByType("AttackCountMax")->front()->getVal();

}

void Creature::increaseAttackCount(){

     this->findCapaByType("AttackCount")->front()->setVal(this->findCapaByType("AttackCount")->front()->getVal()+1);    
}


void Creature::takeDamage(unsigned int damage){

    std::string capaType = "hp";
    std::list<Capacity*>* tempList = this->findCapaByType(capaType);

     
        if (tempList->empty()){
    throw std::logic_error( "no hp capacity in current card" ); 
    }
 
    tempList->front()->setVal(tempList->front()->getVal()-damage);

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

  int newhp=((listHP->front()->getVal()+heal>listMaxHP->front()->getVal())? listMaxHP->front()->getVal() :listHP->front()->getVal()+heal);
    listHP->front()->setVal(newhp);

}



void Creature::increaseMaxHP(unsigned int modifier){

    std::string maxHP = "max_hp";
    std::list<Capacity*>* listMaxHP = this->findCapaByType(maxHP);

     
        if (listMaxHP->empty()){
    throw std::logic_error( "no hp_max capacity in current card" ); 
    }

    listMaxHP->front()->setVal(listMaxHP->front()->getVal()+modifier);

}



void Creature::decreaseMaxHP(unsigned int modifier){

    std::string maxHP = "max_hp";
    std::list<Capacity*>* listMaxHP = this->findCapaByType(maxHP);

     
        if (listMaxHP->empty()){
    throw std::logic_error( "no hp_max capacity in current card" ); 
    }

    listMaxHP->front()->setVal(listMaxHP->front()->getVal()-modifier);

}
