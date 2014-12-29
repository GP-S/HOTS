#include "CreateDeck.h"

static const unsigned int sizeofdeck = 40;
static const std::string namebeast[10] = {"Azarie","Docibilis","Edric","Fenelon","Wilbray","Zenalie","Henreliette","Donatielle","Adelinie","Lizimene"};
static const std::string namespell[10] = {"Fire ball","Acid arrow","Touch of idiocy","Deafness","Explosive runes","Lightning bolt","Wind rage","Flame arrow","Vanish","Storm"};

int myRandom(){
	return (int)std::rand()%10;
}

std::list<Card*>* newDeck(){


	std::cout << "avant init" << std::endl;

	std::srand(std::time(0));
	std::list<Card*> *deck = new std::list<Card*>();
	int strength = 0;
	int life = 0;
	int damage = 0;


	std::cout << "après init" << std::endl;
	

	for(size_t i = 0; i < sizeofdeck/2; i++){


		std::cout << "début boucle beast: " << i << std::endl;

		strength = myRandom();
		life = myRandom();

		Beast *beast = new Beast(namebeast[myRandom()],life,strength,"human");

		std::cout << "beast instancie " << std::endl;

		Effect *hp = new Effect("hp",NULL,life);
		Effect *max_hp = new Effect("hpMax",NULL,life);
		Effect *attack = new Effect("attack",NULL,strength);
		Effect *AttackCount = new Effect("attackCount",NULL,0);
		Effect *AttackCountMax = new Effect("attackCountMax",NULL,1);

		std::cout << "effect instancie " << std::endl;

		Capacity *capa_hp = new Capacity("hp",-1);
		Capacity *capa_max_hp = new Capacity("hpMax",-1);
		Capacity *capa_attack = new Capacity("attack",-1);
		Capacity *capa_AttackCount = new Capacity("attackCount",-1);
		Capacity *capa_AttackCountMax = new Capacity("attackCountMax",-1);

		std::cout << "Capacity instancie " << std::endl;

		capa_hp->setEffect(hp);
		capa_max_hp->setEffect(max_hp);
		capa_attack->setEffect(attack);
		capa_AttackCount->setEffect(AttackCount);
		capa_AttackCountMax->setEffect(AttackCountMax);

		std::cout << "effect ajoute dans capa" << std::endl;

		beast->addCapacity(capa_hp);
		beast->addCapacity(capa_max_hp);
		beast->addCapacity(capa_attack);
		beast->addCapacity(capa_AttackCount);
		beast->addCapacity(capa_AttackCountMax);

		std::cout << "capa ajoutee dans beast" << std::endl;

		beast->calculateCost();

		std::cout << "cout calcule " << std::endl;

		deck->push_back((Card*)beast);

		std::cout << "fin boucle beast: " << i << std::endl;
	}

	for(size_t i = sizeofdeck/2+1; i < sizeofdeck; i++){

		damage = myRandom();

		Spell *spell = new Spell(namespell[myRandom()]);

		Effect *damageeffect = new Effect("damage",NULL,damage);

		Capacity *capa = new Capacity("damage",0);

		capa->setEffect(damageeffect);

		spell->addCapacity(capa);


		spell->calculateCost();
		deck->push_back((Card*)spell);
	}


}