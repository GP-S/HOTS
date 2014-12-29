#include "CreateDeck.h"

void printBeast(Beast *beast,unsigned int max){

	std::cout << "Beast: " << std::endl;
	for(size_t i = 0; i < max; i++){
		std::cout <<	" beast[" << i << "] = ";
		std::cout <<	" Name: " << beast[i].getName();
		std::cout <<	" cardType: " << beast[i].getType();
		std::cout <<	" cost: " << beast[i].getCost();
		std::cout <<	" hp: " << beast[i].getHp();
		std::cout <<	" baseAttack: " << beast[i].getBaseAttack();
		std::cout <<	" race: " << beast[i].getRace() << std::endl;
	} 
}

void printSpell(Spell *spell,unsigned int max){

	std::cout << "Spell: " << std::endl;
	for(size_t i = 0; i < max; i++){
		std::cout <<	" spell[" << i << "] = ";
		std::cout <<	" Name: " << card[i].getName();
		std::cout <<	" cardType: " << card[i].getType();
		std::cout <<	" cost: " << card[i].getCost() << std::endl;
	} 
}

void printCard(Card *card,unsigned int max){

	std::cout << "Card: " << std::endl;
	for(size_t i = 0; i < max; i++){
		std::cout <<	" card[" << i << "] = ";
		std::cout <<	" Name: " << card[i].getName();
		std::cout <<	" cardType: " << card[i].getType();
		std::cout <<	" cost: " << card[i].getCost() << std::endl;
	} 
}

/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){

	std::list<Card*> *deck = newDeck();

	foreach(std::list<Card*>, deck, it){
		printCard(*it,1);
	}

	/*foreach(std::list<Card*>, deck, it){

		if((*it)->getType()=="beast")
			printBeast((Beast*)(*it),1);

		if((*it)->getType()=="spell")
			printSpell((Spell*)(*it),1);
	}*/

	std::cout << "Tout c'est bien passé ! ! ! " << std::endl;

	return 0;
}