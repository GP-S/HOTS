#include "stdafx.h"
#include "Card.h"
/**@TODO : 
*	findByType() : When the doubly linked list template is done, modify this so that 
*	calculateCost() : quand les capas seront fixées .
*
*
*
**/
Card::Card()
{
	name = "";
	cardType = "Card_dafuck";
	capaList = new std::list<Capacity>();

	
}

Card::Card(string name, std::string cardType){
	name = name;
	cardType = cardType;
	capaList = new std::list<Capacity>();
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

std::list<Capacity> Card::findCapaByType(std::string capaType)//returns a list of all capacities of choosen type
{
	capaListTemp = new std::list<Capacity>();
	int i;
	for (i=0;i<capaList.size();i++){
		if (capaList[i].getType()==capaType){
			capaListTemp.push_back(capaList[i]);
		}
	}

	return capaListTemp;

}

Ttype Card::getType()
{
	return cardType;
}

string Card::getName()
{
	return name;
}

float Card::getCost()
{
	return cost;
}