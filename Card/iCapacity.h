#ifndef ICAPACITY_H
#define ICAPACITY_H

#include <string>
#include <list>
#include <iostream>
#include "../Effect/Effect.h"


/** 
* Class iCapacity .
* @author Armand
*
**/

class iCapacity
{

	public :

    /**
    * Default constructor
    * 
    *
    **/
    virtual Capacity() = 0;
    /**
    * Constructor
    * 
    *
    **/
    virtual Capacity(std::string type,int durabilty) = 0;
    /**
    * Destructor
    * 
    *
	**/

  	virtual ~Capacity() {};
    /**
    * getType
    * basic getter
    *
    **/

    virtual std::string getType() = 0;
    /**
    * getdurabilty
    * basic getter
    *
    **/
    virtual int getDurabilty() = 0;
    /**
    * setType
    * basic setter
    *
    **/
    virtual void setType(std::string type) = 0;
    /**
    * setdurabilty
    * basic setter
    *
    **/
    virtual void setDurabilty(int durabilty) = 0;
    /**
    * setActive
    * basic setter
    *
    **/
    virtual void setActive(bool active) = 0;
    /**
    * getActive
    * basic getter
    *
    **/
    virtual bool getActive() = 0;
	virtual Effect* getEffect() = 0;
    virtual void decreaseDurability() = 0;
    virtual void setEffect(Effect* effect) = 0;


};
#endif // ICAPACITY_H