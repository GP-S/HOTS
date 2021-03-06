#include "Card.h"
/**@TODO : 
*	
*	calculateCost() : when the capacities are done .
*
*
*
**/

Card::Card()
{
	name = "";
	cardType = "card_dafuck";
	capaList = new std::list<Capacity*>();

	
}

Card::Card(std::string name, std::string cardType){
	this->name = name;
	this->cardType = cardType;
	capaList = new std::list<Capacity*>();
}


Card::~Card()
{
}

void Card::addCapacity(iCapacity* capa){//insert a Capacity at the tail of the list
	
	capaList->push_back( (Capacity*) capa);
}


void Card::calculateCost(){//modify when capacities are done

	float fcost = 0.0;

	std::for_each(capaList->begin(),capaList->end(), [&fcost,this] (Capacity* it) mutable {

			fcost += it->getEffect()->costVal(this);
		}
	);

	cost = (int)fcost;

}
// i don't know if this is usefull anymore . keeping it just in case
std::list <Capacity*>*  Card::findCapaByType(std::string effectType)//returns a list of all capacities of choosen type
{
	std::list<Capacity*>* capaListTemp = new std::list<Capacity*>();

	std::for_each(capaList->begin(),capaList->end(), [effectType, capaListTemp] (Capacity* it){
		if (it->getEffect()->getType()==effectType)//compare the strings
			capaListTemp->push_back(it);
		}
	);

	return capaListTemp;

}

int Card::getTotal(std::string effectType)//returns the total of the values of a choosen effect type
{
	int total = 0;
	
	std::for_each(capaList->begin(),capaList->end(),[&total,effectType] (Capacity* capaIterator) mutable {
		if (capaIterator->getActive())//if the capacity is active
			if(capaIterator->getEffect()->getType()==effectType)//compare the strings
				total+=capaIterator->getEffect()->getValue();
		}
	);
	
	if (effectType == "hp" && total < 1){
    	throw std::logic_error( "current card has an illegal health" ); 
  	}
  	if (effectType == "attack" && total < 0){
    	throw std::logic_error( "current card has an illegal attack" ); 
  	}

	return total;
}

std::string Card::getType()
{
	return cardType;
}

std::string Card::getName()
{
	return name;
}

int Card::getCost()
{
	return cost;
}

void Card::decreaseAllDurabilty(){

	std::for_each(capaList->begin(),capaList->end(), [] (Capacity* capaIterator){
			capaIterator->decreaseDurability();
		}
	);
}

void Card::setType(std::string type){
  this->cardType = type;
}

void Card::setName(std::string name){
  this->name = name;
}

