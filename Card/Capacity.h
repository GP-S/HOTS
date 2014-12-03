#ifndef CAPACITY_H
#define CAPACITY_H

#include <string>
#include <list>
#include <iostream>


/** 
* Class Capacity . Naive implementation for tests purposes
* @author Armand
*
**/

class Capacity
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
    					Capacity(std::string type,int value);
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

    std::string			getType();
    /**
    * getValue
    * basic getter
    *
    **/
    int					getVal();
    /**
    * setType
    * basic setter
    *
    **/
    void				setType(std::string type);
    /**
    * setValue
    * basic setter
    *
    **/
    void				setVal(int value);
    /**
    * setActive
    * basic setter
    *
    **/
    void                setActive(bool active);
    /**
    * getActive
    * basic getter
    *
    **/
    bool                getActive();

	protected : 

		std::string		type;
		int 			value;
        bool            active;


};
#endif // CAPACITY_H