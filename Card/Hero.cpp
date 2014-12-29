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
   setType("hero");
}


Hero::~Hero()
{
    
}

void Hero::increaseShards(unsigned int modifier){

    std::string shards = "shards";
    std::list<Capacity*>* listShards = this->findCapaByType(shards);

    if (listShards->empty()){
        throw std::logic_error( "no shards capacity in current card" ); 
    }

    int newShards = (listShards->front()->getEffect()->getValue()+modifier)> 10 ? 10 : (listShards->front()->getEffect()->getValue()+modifier);
    listShards->front()->getEffect()->setValue(newShards);

}



void Hero::decreaseShards(unsigned int modifier){

    std::string shards = "shards";
    std::list<Capacity*>* listShards = this->findCapaByType(shards);

    if (listShards->empty()){
        throw std::logic_error( "no shards capacity in current card" ); 
    }

    int newShards = (listShards->front()->getEffect()->getValue()+modifier) < 0 ? 0 : (listShards->front()->getEffect()->getValue()-modifier);
    listShards->front()->getEffect()->setValue(newShards);

}

void Hero::increaseMaxShards(unsigned int modifier){

    std::string shards = "shards";
    std::string maxShards = "maxShards";
    std::list<Capacity*>* listMaxShards = this->findCapaByType(maxShards);
    std::list<Capacity*>* listShards = this->findCapaByType(shards);

    if (listShards->empty()){
        throw std::logic_error( "no maxShards capacity in current card" ); 
    }

	int newMaxShards = (listMaxShards->front()->getEffect()->getValue()+modifier) > 10 ? 10 : (listMaxShards->front()->getEffect()->getValue()+modifier);
    listMaxShards->front()->getEffect()->setValue(newMaxShards);

}



void Hero::decreaseMaxShards(unsigned int modifier){

    std::string shards = "shards";
    std::string maxShards = "maxShards";
    std::list<Capacity*>* listMaxShards = this->findCapaByType(maxShards);
    std::list<Capacity*>* listShards = this->findCapaByType(shards);

    if (listMaxHP->empty()){
        throw std::logic_error( "no maxShards capacity in current card" ); 
    }

    int newMaxShards = (listMaxShards->front()->getEffect()->getValue()-modifier) < 0 ? 0 : (listMaxShards->front()->getEffect()->getValue()-modifier);
    listMaxShards->front()->getEffect()->setValue(newMaxShards);

}

