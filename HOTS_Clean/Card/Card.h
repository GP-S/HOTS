#ifndef CARD_H
#define CARD_H

#include <string>
#include <list>
//#include <tchar.h>
//#include <stdlib.h>
#include <iostream>
#include "Capacity.h"

/** 
* Class Card . 
* @author Armand
*
**/

class Card
{
    public:
    /**
    * Default constructor
    * 
    *
    **/
								Card();
	/**
    * Constructor
    * 
    *
    **/
								Card(string name, std::string cardType);
    /**
    * Destructor
    * Does nothing atm
    *
    **/
								~Card();
    /**
    * getCost
    * Basic getter
    * @return cost the cost of the card
    *
    **/													
		float					getCost();	
    /**
    * calculateCost
    * does nothing atm . modify it .
    *
    **/
		void					calculateCost();
    /**
    * addCapacity
    * adds a capacity to the list of capacities of the capacity list
    *
    **/
		void		 	 		addCapacity(Capacity* capa);
    /**
    * getName
    * basic getter
    * @param Capacity* capa the capacity to add
    * @return name the name of the card
    *
    **/
		string	 				getName();
    /**
    * isAlive
    * tells if a card is alive 
    * @return isAlive the alive flag of a card .
    *
    **/
virtual bool                    isAlive() = false;
    /**
    * findCapaByType
    * returns a list of capacity that matches choosen type
    * @param std::string capaType the type you want to find
    * @return capaListTemp the list of capacities that matches choosen type
    *
    **/
		std::list<Capacity>		findCapaByType(std::string capaType);
    /**
    * getType
    * basic getter
    *
    **/
		std::string				getType();

    

    protected:
        std::string				name;
		float	 				cost;
	    std::list<Capacity>		capaList;
		std::string				cardType;
};

#endif // CARD_H
