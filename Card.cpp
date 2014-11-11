#include "stdafx.h"
#include "Card.h"
/*
todo : 
	findByType() : quand le template ldc est fait, changer pour qu'elle soit propre
	calculateCost() : quand les capas seront fixées .



*/
Card::Card()
{
	name = "";
	type = Card_dafuck;
	firstCapa = NULL;
	lastCapa = NULL;

	
}

Card::Card(string name, Ttype typ){
	name = name;
	type = typ;
	firstCapa = NULL;
	lastCapa = NULL;
}


Card::~Card()
{
}

void Card::addCapacity(Capacity* capa){//insere une capa en queue de la ldc
	
	if (lastCapa != NULL){
		Capacity* temp = lastCapa;
		temp->setNext(capa);
		lastCapa=capa;
	}
	else
	{
		firstCapa = capa;
		lastCapa = capa;
	}

}


Card* Card::getPrev()
{
	return prevCard;
}

Card* Card::getNext()
{
	return nextCard;
}

void Card::setPrev(Card *prev)
{
	prevCard = prev;
}

void Card::setNext(Card *next)
{
	nextCard = next;
	//if(next != NULL) nextCard->setPrev(this);
}

void Card::calculateCost(){//a voir quand les capas seront décidées .

	cost = 5;
}

Capacity* Card::findByType(Ttype type)//pour le moment, renvoit la premiere capa du type choisit . a changer soon(tm)
{
	Capacity *temp = firstCapa;
	while (temp->getType() != type) temp = temp->next();
	return temp;
}

Ttype Card::getType()
{
	return type;
}

string Card::getName()
{
	return name;
}

float Card::getCost()
{
	return cost;
}
