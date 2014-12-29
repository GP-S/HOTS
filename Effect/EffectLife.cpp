// #include "EffectLife.h"

// /**@TODO : 
// *			-i'd like someone to double check this pls .
// *
// *
// **/

// EffectLife::EffectLife(){

// }

// EffectLife::EffectLife(){//complete this

// }

// EffectLife::~EffectLife(){


// }

// void EffectLife::takeDamage(Card* card,unsigned int damage){

// 	std::string capaType = "hp";
// 	std::list tempList = card->findCapaByType(capaType);

     
// 		if (tempList.empty()){
//     throw std::logic_error( "no hp capacity in current card" ); 
//   	}
 
// 	tempList.front.setVal(tempList.front.getVal()-damage);

// }



// void EffectLife::heal(Card* card,unsigned int heal){

// 	std::string hp = "hp";
// 	std::list listHP = card->findCapaByType(hp);

     
// 		if (listHP.empty()){
//     throw std::logic_error( "no hp capacity in current card" ); 
//   	}
 
//  	std::string maxHP = "max_hp";
// 	std::list listMaxHP = card->findCapaByType(maxHP);

     
// 		if (listMaxHP.empty()){
//     throw std::logic_error( "no hp_max capacity in current card" ); 
//   	}

//   int newhp=min(listHP.front.getVal()+heal,listMaxHP.front.getval());
// 	listHP.front.setVal(newhp);

// }



// void EffectLife::increaseMaxHP(Card* card,unsigned int modifier){

// 	std::string maxHP = "max_hp";
// 	std::list listMaxHP = card->findCapaByType(maxHP);

     
// 		if (listMaxHP.empty()){
//     throw std::logic_error( "no hp_max capacity in current card" ); 
//   	}

// 	listMaxHP.front.setVal(listMaxHP.front.getval()+modifier);

// }



// void EffectLife::decreaseMaxHP(Card* card,unsigned int modifier){

// 	std::string maxHP = "max_hp";
// 	std::list listMaxHP = card->findCapaByType(maxHP);

     
// 		if (listMaxHP.empty()){
//     throw std::logic_error( "no hp_max capacity in current card" ); 
//   	}

// 	listMaxHP.front.setVal(listMaxHP.front.getval()-modifier);

// }
