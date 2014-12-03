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
	cardType = "Card_dafuck";
	capaList = new std::list<Capacity*>();

	
}

Card::Card(std::string name, std::string cardType){
	name = name;
	cardType = cardType;
	capaList = new std::list<Capacity*>();
}


Card::~Card()
{
}

void Card::addCapacity(Capacity* capa){//insert a Capacity at the tail of the list
	
	capaList.push_back(capa);

}


void Card::calculateCost(){//modify when capacities are done

	cost = 5;
}

std::list<Capacity*> Card::findCapaByType(std::string capaType)//returns a list of all capacities of choosen type
{
	std::list<Capacity*> capaListTemp = new std::list<Capacity*>();
	int i;
	for (i=0;i<capaList.size();i++){
		if (capaList[i]->getType()==capaType){
			capaListTemp.push_back(capaList[i]);
		}
	}

	return capaListTemp;

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

bool Card::isUsable(Player p)
{

	return true;
}


