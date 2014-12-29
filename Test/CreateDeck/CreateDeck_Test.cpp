#include "CreateDeck.h"

void printBeast(Beast *beast){

	std::cout << "Beast: " << std::endl;

	std::cout <<	" Name: " << beast->getName();
	std::cout <<	" cardType: " << beast->getType();
	std::cout <<	" cost: " << beast->getCost();
	std::cout <<	" hp: " << beast->getHp();
	std::cout <<	" baseAttack: " << beast->getBaseAttack();
	std::cout <<	" race: " << beast->getRace() << std::endl;
}

void printSpell(Spell *spell){

	std::cout << "Spell: " << std::endl;

	std::cout <<	" Name: " << spell->getName();
	std::cout <<	" cardType: " << spell->getType();
	std::cout <<	" cost: " << spell->getCost() << std::endl; 
}

void printCard(Card *card){

	std::cout << "Card: " << std::endl;

	std::cout <<	" Name: " << card->getName();
	std::cout <<	" cardType: " << card->getType();
	std::cout <<	" cost: " << card->getCost() << std::endl;
}

void printEffect(Effect *effect,Card *card){

	std::cout << "Effect: " << std::endl;

	std::cout <<	" type: " << effect->getType();
	std::cout <<	" affinity: " << effect->getAffinity();
	std::cout <<	" value: " << effect->getValue();		
	std::cout <<	" cost value: " << effect->costVal(card) << std::endl;
}


/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){

	std::list<Card*> *deck = newDeck();

	std::cout << "Deck cree" << std::endl;

//	foreach(std::list<Card*>, deck, it){
	for(std::list<Card*>::iterator it = deck->begin(); it!=deck->end(); ++it){
		std::cout << "*it: " << (*it) << std::endl;

		printCard((*it));
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