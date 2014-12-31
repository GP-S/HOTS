#include "CreateDeck.h"

#define ALLCAPA 9

static const std::string capaName[ALLCAPA] = {	"attack","attackCount","attackCountMax",
												"damage","hp","hpMax","shards",
												"shardsMax","effect"
											 };

void printBeast(Beast *beast){

	std::cout << "  Beast: " << std::endl;

	std::cout <<	"   Name: " << beast->getName();
	std::cout <<	"   cardType: " << beast->getType();
	std::cout <<	"   cost: " << beast->getCost();
	std::cout <<	"   hp: " << beast->getHp();
	std::cout <<	"   baseAttack: " << beast->getBaseAttack();
	std::cout <<	"   race: " << beast->getRace() << std::endl;
}

void printSpell(Spell *spell){

	std::cout << "  Spell: " << std::endl;

	std::cout <<	"   Name: " << spell->getName();
	std::cout <<	"   cardType: " << spell->getType();
	std::cout <<	"   cost: " << spell->getCost() << std::endl; 
}

void printCard(Card *card){

	std::cout << std::endl;
	std::cout << "**********************Card*********************" << std::endl;

	std::cout <<	" cost: " << card->getCost();
	std::cout <<	" cardType: " << card->getType();
	std::cout <<	" Name: " << card->getName() << std::endl;
}

void printEffect(Card *card,std::string type){

	std::list<Capacity*>* capaList = card->findCapaByType(type);

	if(capaList->size()>0){
		Effect *effect = capaList->front()->getEffect();

		std::cout <<	"     cost value: " << effect->costVal(card);
		std::cout <<	"     affinity: " << effect->getAffinity();
		std::cout <<	"     value: " << effect->getValue();		
		std::cout <<	"     type: " << effect->getType() << std::endl;
	}
}


/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){

	std::list<iCard*> *deck = newDeck();
	std::list<Capacity*> *capa = new std::list<Capacity*>();
	std::cout << "Deck cree, size: " << deck->size() << std::endl;

	// std::for_each(deck->begin(),deck->end(), [] (iCard* it){
	// 	printCard(it);

	// 	if(it->getType() == "beast"){
	// 		printBeast((Beast*)it);

	// 		std::cout << "    Effect: " << std::endl;
	// 		printEffect(it,"attack");
	// 		printEffect(it,"attackCount");
	// 		printEffect(it,"attackCountMax");
	// 		printEffect(it,"hp");
	// 		printEffect(it,"hpMax");
	// 	}

	// 	if(it->getType() == "spell")
	// 		printSpell((Spell*)it);
	// 		printEffect(it,"damage");
	// 	}
	// );


	std::for_each(deck->begin(),deck->end(), [capa] (iCard* itcard){
		printCard((Card*)itcard);

		for(size_t i = 0 ; i < ALLCAPA; i++){

			capa = dynamic_cast<Card*>(it)->findCapaByType(capaName[i]);
			std::for_each(capa->begin(),capa->end(), [] (Capacity* itcapa){
					printEffect(itcapa->getEffect());
				}
			);
		}
		}
	);

	std::cout << "Tout c'est bien passé ! ! ! " << std::endl;

	return 0;
}