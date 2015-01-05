#include "CreateDeck.h"

static const unsigned int sizeofdeck = 10;

static const std::string namebeast[16] = {	"Socrate","Platon","Aristote","Confucius",
											"Sénèque","Averroès","Montaigne","Descartes",
											"Erasme","Voltaire","Moontesquieu","Rousseau",
											"Diderot","Kant","Marx","Nietzsche"
										 };

static const std::string namespell[10] = {	"Fire ball","Acid arrow","Touch of idiocy",
											"Deafness","Explosive runes","Lightning bolt",
											"Wind rage","Flame arrow","Vanish","Storm"
										 };

int myRandom(unsigned int mod){
	return (int)std::rand()%mod;
}

std::list<iCard*>* newDeck(){

	std::srand(std::time(0));
	std::list<iCard*> *deck = new std::list<iCard*>();
	int strength = 0;
	int life = 0;
	int damage = 0;

	for(size_t i = 0; i < sizeofdeck; i++){

		if(!myRandom(3)){

			damage = myRandom(10)+1;

			Spell *spell = newSpell(namespell[myRandom(10)],damage);
			
			deck->push_back((iCard*)spell);

		}
		else{
			strength = myRandom(11);
			life = myRandom(10)+1;

			Beast *beast = newBeast(namebeast[myRandom(16)],life,strength,"human");

			deck->push_back((iCard*)beast);
		}
	}

	return deck;
}