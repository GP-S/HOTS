#include "creatdeck.h"

/*
list of minimal capacity for beast and spell:

beast:
hp
max_hp
attack
AttackCount
AttackCountMax

spell:

*/

static const unsigned int sizeofdeck 40;
static const std::string namebeast[10] = {"Azarie","Docibilis","Edric","Fenelon","Wilbray","Zenalie","Henreliette","Donatielle","Adelinie","Lizimene"};
static const std::string namespell[10] = {"Fire ball","Acid arrow","Touch of idiocy","Deafness","Explosive runes","Lightning bolt","Wind rage","Flame arrow","Vanish","Storm"};

int random(){
	return std::rand()%10;
}

std::list<Card*>* newDeck(){

	std::srand(std::time(0));
	std::list<Card*> *deck = new std::list<Card*>();
	int strength = 0;
	int life = 0;
	int damage = 0;
	

	for(size_t i = 0; i < sizeofdeck/2; i++){

		strength = random();
		life = random();

		Beast *beast = new Beast(namebeast(random()),life,strength,"human");

		Effect *hp = new Effect("hp",NULL,life);
		Effect *max_hp = new Effect("hpMax",NULL,life);
		Effect *attack = new Effect("attack",NULL,strength);
		Effect *AttackCount = new Effect("attackCount",NULL,0);
		Effect *AttackCountMax = new Effect("attackCountMax",NULL,1);

		Capacity *capa_hp = new Capacity("hp",-1);
		Capacity *capa_max_hp = new Capacity("hpMax",-1);
		Capacity *capa_attack = new Capacity("attack",-1);
		Capacity *capa_AttackCount = new Capacity("attackCount",-1);
		Capacity *capa_AttackCountMax = new Capacity("attackCountMax",-1);

		capa_hp->setEffect(hp);
		capa_max_hp->setEffect(max_hp);
		capa_attack->setEffect(attack);
		capa_AttackCount->setEffect(AttackCount);
		capa_AttackCountMax->setEffect(AttackCountMax);

		beast->addCapacity(capa_hp);
		beast->addCapacity(capa_max_hp);
		beast->addCapacity(capa_attack);
		beast->addCapacity(capa_AttackCount);
		beast->addCapacity(capa_AttackCountMax);

		beast->calculateCost();
		deck->push_back((Card*)beast);
	}

	for(size_t i = sizeofdeck/2+1; i < sizeofdeck; i++){

		damage = random();

		Spell *spell = new Spell(namespell(random()));

		Effect *damage = new Effect("damage",NULL,damage);

		Capacity *capa = new Capacity("damage",0);

		capa->setEffect(damage);

		spell->addCapacity(capa);


		spell->calculateCost();
		deck->push_back((Card*)spell);
	}


}