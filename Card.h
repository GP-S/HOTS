#ifndef CARD_H
#define CARD_H

#include <string>
//#include <tchar.h>
//#include <stdlib.h>
#include <iostream>
#include "Capacity.h"

using namespace std;

class Card
{
    public:
					Card();
					Card(string name, Ttype typ);
					~Card();
		float		getCost();	
		void		calculateCost();
		void	  	addCapacity(Capacity* capa);
		Card	  	*getPrev();
		Card	  	*getNext();
		void	  	setPrev(Card* prev);
		void	  	setNext(Card* next);
		string	  	getName();
		virtual   	bool isAlive() = 0;
		Capacity  	*findByType(Ttype type);
		Ttype	  	getType();

    

    protected:
        string		name;
		float 		cost;
        //char		type;
        Capacity	*firstCapa;
        Capacity 	*lastCapa;
		Ttype		type;
		Card		*prevCard;
		Card		*nextCard;
};

#endif // CARD_H
