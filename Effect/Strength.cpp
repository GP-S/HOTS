#include "Strength.h"

/**@TODO : 
*			-i'd like someone to double check this pls .
*
*
**/

Strength::Strength(){

}

Strength::Strength(){//complete this

}

Strength::~Strength(){


}

void Strength::increaseStrength(Card* card,unsigned int modifier){

	std::string strength = "strength";
	std::list listStrength = card->findCapaByType(strength);

     
		if (listStrength.empty()){
    throw std::logic_error( "no strength capacity in current card" ); 
  	}

	listStrength.front.setVal(listStrength.front.getval()+n);

}
void Strength::decreaseStrength(Card* card,unsigned int modifier){

	std::string strength = "strength";
	std::list listStrength = card->findCapaByType(strength);

     
		if (listStrength.empty()){
    throw std::logic_error( "no strength capacity in current card" ); 
  	}

	listStrength.front.setVal(listStrength.front.getval()-n);

}
void Strength::increaseBaseStrength(Card* card,unsigned int modifier){

	std::string baseStrength = "base_strength";
	std::list listBaseStrength = card->findCapaByType(baseStrength);

     
		if (listBaseStrength.empty()){
    throw std::logic_error( "no base_strength capacity in current card" ); 
  	}

	listBaseStrength.front.setVal(listBaseStrength.front.getval()+n);

}
void Strength::decreaseBaseStrength(Card* card,unsigned int modifier){

	std::string baseStrength = "base_strength";
	std::list listBaseStrength = card->findCapaByType(baseStrength);

     
		if (listBaseStrength.empty()){
    throw std::logic_error( "no base_strength capacity in current card" ); 
  	}

	listBaseStrength.front.setVal(listBaseStrength.front.getval()-n);
}



