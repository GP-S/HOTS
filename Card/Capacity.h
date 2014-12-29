#ifndef CAPACITY_H
#define CAPACITY_H

#include <string>
#include <list>
#include <iostream>
#include "../Effect/iEffect.h"


/** 
* Class Capacity . upgraded implementation for tests purposes
* @author Armand
*
**/

class Capacity : public iCapacity
{

	public :

    /**
    * Default constructor
    * 
    *
    **/
    Capacity();
    /**
    * Constructor
    * 
    *
    **/
    Capacity(std::string type,int durabilty);
    /**
    * Destructor
    * 
    *
	**/

  	~Capacity();
    /**
    * getType
    * basic getter
    *
    **/

    std::string getType();
    /**
    * getdurabilty
    * basic getter
    *
    **/
    int getDurabilty();
    /**
    * setType
    * basic setter
    *
    **/
    void setType(std::string type);
    /**
    * setdurabilty
    * basic setter
    *
    **/
    void setDurabilty(int durabilty);
    /**
    * setActive
    * basic setter
    *
    **/
    void setActive(bool active);
    /**
    * getActive
    * basic getter
    *
    **/
    bool getActive();
	iEffect* getEffect();
    void decreaseDurability();
    void setEffect(iEffect* effect);

	protected : 

	std::string		type;
	int 			durabilty;
    bool            active;
    iEffect          *effect;



};
#endif // CAPACITY_H