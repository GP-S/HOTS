#include "Card.h"
/**@TODO : 
*	
*	calculateCost() : when the capacities are done .
*
*
*
**/

#define foreach(T, c, i) for(T::iterator i = c->begin(); i!=c->end(); ++i)



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

	cost = 0;

	foreach(std::list<Capacity*>, capaList, it){
		cost += (*it)->getEffect()->costVal(this);
	}

}
// i don't know if this is usefull anymore . keeping it just in case
std::list <Capacity*>*  Card::findCapaByType(std::string effectType)//returns a list of all capacities of choosen type
{
	std::list<Capacity*>* capaListTemp = new std::list<Capacity*>();

	foreach(std::list<Capacity*>, capaList, it){
		if ((*it)->getEffect()->getType()==effectType){//compare the strings
			capaListTemp->push_back(*it);
		}
	}

	return capaListTemp;

}
/*well it seems that capacity only has ONE effect .
int Card::getTotal(std::string effectType)//returns the total of the values of a choosen effect type
{
	int total =0;
	foreach(std::list<Capacity*>, capaList, capaIterator){
		if ((*capaIterator)->getActive()){//if the capacity is active
			foreach(std::list<Effect*>, capaIterator->effectList, effectIterator){
			if ((*effectIterator)->getType()==capaType){//compare the strings
				total+=(*effectIterator)->getValue();
				}
			}
		}
	}

	if (effectType=="hp" && total<1){
    throw std::logic_error( "current card has an illegal health" ); 
  	}
  	if (effectType=="attack" && total<0){
    throw std::logic_error( "current card has an illegal attack" ); 
  	}

	return total;
}
*/

int Card::getTotal(std::string effectType)//returns the total of the values of a choosen effect type
{
	int total = 0;
	
	foreach(std::list<Capacity*>, capaList, capaIterator){
		if ((*capaIterator)->getActive()){//if the capacity is active
			if((*capaIterator)->getEffect()->getType()==effectType){//compare the strings
				total+=(*capaIterator)->getEffect()->getValue();
				}
			}
		}
	

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

// bool Card::isUsable(Player p)
// {

// 	return true;
// }

void Card::decreaseAllDurabilty(){

	foreach(std::list<Capacity*>, capaList, capaIterator){
		(*capaIterator)->decreaseDurability();
	}
}

void Card::setType(std::string type){
  this->cardType = type;
}

void Card::setName(std::string name){
  this->name = name;
}

