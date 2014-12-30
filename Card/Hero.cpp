#include "Hero.h"

#define MAXSHARDS 10

Hero::Hero() :
Creature()
{
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

    std::list<Capacity*>* listShards = this->findCapaByType("shards");

    if (listShards->empty()){
        throw std::logic_error( "no shards capacity in current card" ); 
    }

    int newShards = (listShards->front()->getEffect()->getValue()+modifier)> MAXSHARDS ? MAXSHARDS : (listShards->front()->getEffect()->getValue()+modifier);
    listShards->front()->getEffect()->setValue(newShards);

}



void Hero::decreaseShards(unsigned int modifier){

    std::list<Capacity*>* listShards = this->findCapaByType("shards");

    if (listShards->empty()){
        throw std::logic_error( "no shards capacity in current card" ); 
    }

    int newShards = (listShards->front()->getEffect()->getValue()+modifier) < 0 ? 0 : (listShards->front()->getEffect()->getValue()-modifier);
    listShards->front()->getEffect()->setValue(newShards);

}

void Hero::increaseMaxShards(unsigned int modifier){

    std::list<Capacity*>* listMaxShards = this->findCapaByType("shardsMax");

    if (listMaxShards->empty()){
        throw std::logic_error( "no maxShards capacity in current card" ); 
    }

	int newMaxShards = (listMaxShards->front()->getEffect()->getValue()+modifier) > MAXSHARDS ? MAXSHARDS : (listMaxShards->front()->getEffect()->getValue()+modifier);
    listMaxShards->front()->getEffect()->setValue(newMaxShards);

}



void Hero::decreaseMaxShards(unsigned int modifier){

    std::list<Capacity*>* listMaxShards = this->findCapaByType("shardsMax");

    if (listMaxShards->empty()){
        throw std::logic_error( "no maxShards capacity in current card" ); 
    }

    int newMaxShards = (listMaxShards->front()->getEffect()->getValue()-modifier) < 0 ? 0 : (listMaxShards->front()->getEffect()->getValue()-modifier);
    listMaxShards->front()->getEffect()->setValue(newMaxShards);

}

