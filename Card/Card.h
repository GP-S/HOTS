#ifndef CARD_H
#define CARD_H

#include <string>
#include <list>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include "Capacity.h"
#include "Player.h"
#include "iCard.h"


/** 
* Class Card . 
* @author Armand
*
**/

class Card : public iCard
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
    	Card(std::string name, std::string cardType);
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
    	int	getCost();	
        /**
        * setType
        * basic setter
        *
        **/
        void setType(std::string type);
        /**
        * setName
        * basic setter
        *
        **/
        void setName(std::string name);
            
        /**
        * calculateCost
        * does nothing atm . modify it .
        *
        **/
    	void calculateCost();
        /**
        * addCapacity
        * adds a capacity to the list of capacities of the capacity list
        *
        **/
    	void addCapacity(iCapacity* capa);
        /**
        * getName
        * basic getter
        * @param Capacity* capa the capacity to add
        * @return name the name of the card
        *
        **/
    	std::string getName();
        /**
        * isAlive
        * tells if a card is alive 
        * @return isAlive the alive flag of a card .
        *
        **/
        virtual bool isAlive() = 0;
        /**
        * findCapaByType
        * returns a list of capacity that matches choosen type
        * @param std::string capaType the type you want to find
        * @return capaListTemp the list of capacities that matches choosen type
        *
        **/
		std::list<Capacity*>* findCapaByType(std::string capaType);
        /**
        * getType
        * basic getter
        *
        **/
    	std::string	getType();
        /**
        * isUsable
        * tells if a card can be used or not
        * @param
        *
        * not done yet !!!
        **/
//        bool isUsable(Player* p);

        /**
        * getTotal
        * returns the total of the values of a choosen effect type
        * throws exception if : hp < 0 OR attack < 1
        * @param std::string effectType the type you want to find
        * @return total : the total of the values of a choosen effect type
        * 
        **/
        int getTotal(std::string effectType);

        void decreaseAllDurabilty();

    protected:
        std::string				name;
		std::string				cardType;
        int                     cost;
        std::list<Capacity*> *  capaList;
        Player*                 owner;

};

#endif //CARD_H
