#ifndef ICARD_H
#define ICARD_H

#include "iCapacity.h"


/**
* class iCard.
* @author Armand
*/
class iCard
{
public:

    /**
    * virtual destructor
    * for vtable
    **/
    virtual ~iCard(){}
	
	virtual int getCost()=0;	
    /**
    * calculateCost
    * does nothing atm . modify it .
    *
    **/
	virtual void calculateCost()=0;
    /**
    * addCapacity
    * adds a capacity to the list of capacities of the capacity list
    *
    **/
	virtual void addCapacity(iCapacity* capa)=0;
    /**
    * getName
    * basic getter
    * @param Capacity* capa the capacity to add
    * @return name the name of the card
    *
    **/
	virtual std::string	getName()=0;
    /**
    * isAlive
    * tells if a card is alive 
    * @return isAlive the alive flag of a card .
    *
    **/
    virtual bool isAlive() = 0;
    /**
    * getType
    * basic getter
    *
    **/
	virtual std::string	getType()=0;
    /**
    * isUsable
    * tells if a card can be used or not
    * @param
    *
    * not done yet !!!
    **/
//    virtual bool isUsable(Player p)=0;

    /**
    * getTotal
    * returns the total of the values of a choosen effect type
    * throws exception if : hp < 0 OR attack < 1
    * @param std::string effectType the type you want to find
    * @return total : the total of the values of a choosen effect type
    * 
    **/
    virtual int getTotal(std::string effectType)=0;

    virtual void decreaseAllDurabilty()=0;

};

#endif // ICARD_H
