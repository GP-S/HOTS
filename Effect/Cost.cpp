#include "Cost.h"

/**@TODO : 
*			-i'd like someone to double check this pls .
*
*
**/    	

Cost::Cost(){


}

Cost::Cost(){//complete this


}

Cost::~Cost(){


}

void Cost::increaseCost(Card* card,unsigned int modifier){

	std::string cost = "cost";
	std::list listCost = card->findCapaByType(cost);

     
		if (listCost.empty()){
    throw std::logic_error( "no cost capacity in current card" ); 
  	}

	listCost.front.setVal(listCost.front.getval()+n);

}

void Cost::decreaseCost(Card* card,unsigned int modifier){

	std::string cost = "cost";
	std::list listCost = card->findCapaByType(cost);

     
		if (listCost.empty()){
    throw std::logic_error( "no cost capacity in current card" ); 
  	}

	listCost.front.setVal(listCost.front.getval()-n);

}