#ifndef CARD_H
#define CARD_H

#include <string>
#include <list>
//#include <tchar.h>
//#include <stdlib.h>
#include <iostream>
#include "Capacity.h"

/** 
* Class Card . Derived from Card  .
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
    * Default constructor
    * 
    *
    **/
													Card(string name, std::string cardType);
    /**
    * Default constructor
    * 
    *
    **/
													~Card();
    /**
    * Default constructor
    * 
    *
    **/													
		float									getCost();	
    /**
    * Default constructor
    * 
    *
    **/
		void									calculateCost();
    /**
    * Default constructor
    * 
    *
    **/
		void		 	 						addCapacity(Capacity* capa);
    /**
    * Default constructor
    * 
    *
    **/
		string	 						 	getName();
    /**
    * Default constructor
    * 
    *
    **/
		virtual   						bool isAlive() = 0;
    /**
    * Default constructor
    * 
    *
    **/
		std::list<Capacity>		findCapaByType(std::string capaType);
    /**
    * Default constructor
    * 
    *
    **/
		Ttype	  							getType();

    

    protected:
      std::string							name;
			float	 									cost;
	    std::list<Capacity>			capaList;
			std::string							cardType;
};

#endif // CARD_H
