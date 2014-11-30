#ifndef CAPACITY_H
#define CAPACITY_H

#include <string>
#include <list>
//#include <tchar.h>
//#include <stdlib.h>
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
    int					getValue();
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
    void				setValue(int value);

	protected : 


	private :

		std::string		type;
		int 			value;


};
#endif // CAPACITY_H