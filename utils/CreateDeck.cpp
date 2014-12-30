#include "CreateDeck.h"

static const unsigned int sizeofdeck = 40;
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

Hero* newHero(std::string name){

	Hero* hero = new Hero(name,30,0);

	Effect *hero_hp = new Effect("hp","none",30);
	Effect *hero_hpMax = new Effect("hpMax","none",30);
	Effect *hero_attack = new Effect("attack","none",0);
	Effect *hero_attackCount = new Effect("attackCount","none",0);
	Effect *hero_attackCountMax = new Effect("attackCountMax","none",0);
	Effect *hero_shards = new Effect("shards","none",0);
	Effect *hero_shardsMax = new Effect("shardsMax","none",0);

	Capacity *capa_hero_hp = new Capacity("hp",-1);
	Capacity *capa_hero_hpMax = new Capacity("hpMax",-1);
	Capacity *capa_hero_attack = new Capacity("attack",-1);
	Capacity *capa_hero_attackCount = new Capacity("attackCount",-1);
	Capacity *capa_hero_attackCountMax = new Capacity("attackCountMax",-1);
	Capacity *capa_hero_shards = new Capacity("shards",-1);
	Capacity *capa_hero_shardsMax = new Capacity("shardsMax",-1);

	capa_hero_hp->setActive(true);
	capa_hero_hpMax->setActive(true);
	capa_hero_attack->setActive(true);
	capa_hero_attackCount->setActive(true);
	capa_hero_attackCountMax->setActive(true);
	capa_hero_shards->setActive(true);
	capa_hero_shardsMax->setActive(true);
	capa_hero_hp->setEffect(hero_hp);
	capa_hero_hpMax->setEffect(hero_hpMax);
	capa_hero_attack->setEffect(hero_attack);
	capa_hero_attackCount->setEffect(hero_attackCount);
	capa_hero_attackCountMax->setEffect(hero_attackCountMax);
	capa_hero_shards->setEffect(hero_shards);
	capa_hero_shardsMax->setEffect(hero_shardsMax);

	hero->addCapacity(capa_hero_hp);
	hero->addCapacity(capa_hero_hpMax);
	hero->addCapacity(capa_hero_attack);
	hero->addCapacity(capa_hero_attackCount);
	hero->addCapacity(capa_hero_attackCountMax);
	hero->addCapacity(capa_hero_shards);
	hero->addCapacity(capa_hero_shardsMax);

	return hero;

}

std::list<Card*>* newDeck(){

	std::srand(std::time(0));
	std::list<Card*> *deck = new std::list<Card*>();
	int strength = 0;
	int life = 0;
	int damage = 0;

	for(size_t i = 0; i < sizeofdeck; i++){

		if(!myRandom(3)){

			damage = myRandom(10)+1;

			Spell *spell = new Spell(namespell[myRandom(10)]);

			Effect *damageeffect = new Effect("damage","none",damage);

			Capacity *capa = new Capacity("damage",0);

			capa->setActive(true);
			capa->setEffect(damageeffect);
			spell->addCapacity(capa);
			spell->calculateCost();
			
			deck->push_back((Card*)spell);

		}
		else{
			strength = myRandom(11);
			life = myRandom(10)+1;

			Beast *beast = new Beast(namebeast[myRandom(16)],life,strength,"human");

			Effect *hp = new Effect("hp","none",life);
			Effect *hpMax = new Effect("hpMax","none",life);
			Effect *attack = new Effect("attack","none",strength);
			Effect *attackCount = new Effect("attackCount","none",0);
			Effect *attackCountMax = new Effect("attackCountMax","none",1);

			Capacity *capa_hp = new Capacity("hp",-1);
			Capacity *capa_hpMax = new Capacity("hpMax",-1);
			Capacity *capa_attack = new Capacity("attack",-1);
			Capacity *capa_attackCount = new Capacity("attackCount",-1);
			Capacity *capa_attackCountMax = new Capacity("attackCountMax",-1);

			capa_hp->setActive(true);
			capa_hpMax->setActive(true);
			capa_attack->setActive(true);
			capa_attackCount->setActive(true);
			capa_attackCountMax->setActive(true);
			capa_hp->setEffect(hp);
			capa_hpMax->setEffect(hpMax);
			capa_attack->setEffect(attack);
			capa_attackCount->setEffect(attackCount);
			capa_attackCountMax->setEffect(attackCountMax);

			beast->addCapacity(capa_hp);
			beast->addCapacity(capa_hpMax);
			beast->addCapacity(capa_attack);
			beast->addCapacity(capa_attackCount);
			beast->addCapacity(capa_attackCountMax);

			beast->calculateCost();

			deck->push_back((Card*)beast);
		}
	}

	return deck;
}