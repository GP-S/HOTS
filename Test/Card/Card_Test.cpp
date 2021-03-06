#include "Card_Test.h"

#define NUMBER 5
#define ALLCAPA 9

static unsigned int etape = 0;
static std::list<Capacity*>* capalist = new std::list<Capacity*>();
static const std::string cardName[NUMBER] = {"alpha","fire","dafuck","beta","omega"};
static const std::string cardType[NUMBER] = {"beast","spell","card_dafuck","creature","hero"};
static const std::string cardRace[NUMBER] = {"human","robot","none","none","none"};
static const std::string capaName[ALLCAPA] = {	"attack","attackCount","attackCountMax",
												"damage","hp","hpMax","shards",
												"shardsMax","effect"
											 };



void printEtape(std::string text){
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	etape++;
	std::cout << "***etape " << etape << text << " *** " << std::endl;
}

void printBeast(Beast *beast){

	std::cout << "Beast: " << std::endl;

	std::cout <<	"  Name: " << beast->getName();
	std::cout <<	"  cardType: " << beast->getType();
	std::cout <<	"  cost: " << beast->getCost();
	std::cout <<	"  hp: " << beast->getHp();
	std::cout <<	"  baseAttack: " << beast->getBaseAttack();
	std::cout <<	"  race: " << beast->getRace() << std::endl;
}

void printHero(Hero *hero){

	std::cout << "Hero: " << std::endl;

	std::cout <<	"  Name: " << hero->getName();
	std::cout <<	"  cardType: " << hero->getType();
	std::cout <<	"  cost: " << hero->getCost();
	std::cout <<	"  hp: " << hero->getHp();
	std::cout <<	"  baseAttack: " << hero->getBaseAttack() << std::endl; 
}

void printCreature(Creature *creature){

	std::cout << "Creature: " << std::endl;

	std::cout <<	"  Name: " << creature->getName();
	std::cout <<	"  cardType: " << creature->getType();
	std::cout <<	"  cost: " << creature->getCost();
	std::cout <<	"  hp: " << creature->getHp();
	std::cout <<	"  baseAttack: " << creature->getBaseAttack() << std::endl; 
}

void printSpell(Spell *spell){

	std::cout << "Spell: " << std::endl;

	std::cout <<	"  Name: " << spell->getName();
	std::cout <<	"  cardType: " << spell->getType();
	std::cout <<	"  cost: " << spell->getCost() << std::endl; 
}

void printCard(Card *card){

	std::cout << "Card: " << std::endl;

	std::cout <<	"  Name: " << card->getName();
	std::cout <<	"  cardType: " << card->getType();
	std::cout <<	"  cost: " << card->getCost() << std::endl; 
}

void printIsAlive(Creature * creature){

	std::cout << creature->getName();
	std::cout <<	" is ";
	if(creature->isAlive())
		std::cout << "alive" << std::endl;
	else
		std::cout << "dead" << std::endl; 
}

void printCanAttack(Creature * creature){

	std::cout << creature->getName();
	if(creature->canAttack())
		std::cout << "can ";
	else
		std::cout << "can't ";

	std::cout <<	" attack " << std::endl; 
}

void printAllCapa(Card *card,std::string name){

	std::cout << "Print all capa of " << name << std::endl;

	for(size_t i = 0; i < ALLCAPA; i++){

		capalist =  card->findCapaByType(capaName[i]);

		std::for_each(capalist->begin(),capalist->end(), [] (Capacity* it){
			printCapacity(it);
			}
		);	
	}
}

void printEffect(Effect *effect){

	std::cout << "Effect: " << std::endl;
		
	std::cout <<	" cost value: " << effect->costVal();
	std::cout <<	" affinity: " << effect->getAffinity();
	std::cout <<	" value: " << effect->getValue();		
	std::cout <<	" type: " << effect->getType() << std::endl;

}

void printCapacity(Capacity *capacity){

	std::cout << "Capacity: " << std::endl;

	std::cout <<	" active: " << capacity->getActive();	

	if(capacity->getDurabilty() == -1)
		std::cout <<	" durabilty: infinity";
	else
		std::cout <<	" durabilty: " << capacity->getDurabilty();

	std::cout <<	" value effect: " << capacity->getEffect()->getValue(); 
	std::cout <<	" type: " << capacity->getType() << std::endl; 
}

void printCapa(Card *card,std::string capaName,std::string name){

	std::cout << "Print capa of " << name << std::endl;

	capalist =  card->findCapaByType(capaName);

	std::for_each(capalist->begin(),capalist->end(), [] (Capacity* it){
		printCapacity(it);
		}
	);
}

/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){


/*=================================etape  1=========================================*/
/*I Instance all diferent Card*/
	printEtape(": Instanciation of all Cards type");
	Card *card = new Card();
	Spell *spell = new Spell();
	Creature *creature = new Creature();
	Hero *hero = new Hero();
	Beast *beast = new Beast();

	Card *anotherCard = new Card("card","card_dafuck");
	Spell *anotherSpell = new Spell("Lightning bolt");
	Creature *anotherCreature = new Creature("creature",2,3);
	Hero *anotherHero = new Hero("Arthas",30,0);
	Beast *anotherBeast = new Beast("Nicolas",1,0,"human");


/*=================================etape  2=========================================*/
/*I Initialise all Cards*/
	printEtape(": Intialisation of cards");

	card->setName(cardName[2]);
	card->setType(cardType[2]);
	card->calculateCost();

	printCard(card);

	beast->setName(cardName[0]);
	beast->setType(cardType[0]);
	beast->setHp(5);
	beast->setBaseAttack(1);
	beast->setRace(cardRace[0]);
	beast->calculateCost();

	printBeast(beast);
	
	creature->setName(cardName[3]);
	creature->setType(cardType[3]);
	creature->setHp(1);
	creature->setBaseAttack(1);
	creature->calculateCost();
	
	printCreature(creature);

	hero->setName(cardName[4]);
	hero->setType(cardType[4]);
	hero->setHp(30);
	hero->setBaseAttack(0);
	hero->calculateCost();
	
	printHero(hero);

	spell->setName(cardName[1]);
	spell->setType(cardType[1]);
	spell->calculateCost();

	printSpell(spell);

	std::cout << "anotherCard" << std::endl;

	printCard(anotherCard);
	printBeast(anotherBeast);
	printCreature(anotherCreature);
	printHero(anotherHero);
	printSpell(anotherSpell);

/*=================================etape  3=========================================*/
/*I add some Capacity to beast, spell and hero*/
	printEtape(": Add capacity to beast,spell and hero");


/*Beast*//*Beast*//*Beast*//*Beast*//*Beast*//*Beast*//*Beast*/
	Effect *beast_hp = new Effect("hp","none",5);
	Effect *beast_hpMax = new Effect("hpMax","none",5);
	Effect *beast_attack = new Effect("attack","none",5);
	Effect *beast_attackCount = new Effect("attackCount","none",0);
	Effect *beast_attackCountMax = new Effect("attackCountMax","none",1);
	Effect *beast_effect1 = new Effect("effect","none",1);
	Effect *beast_effect2 = new Effect("effect","none",5);

	Capacity *capa_beast_hp = new Capacity("hp",-1);
	Capacity *capa_beast_hpMax = new Capacity("hpMax",-1);
	Capacity *capa_beast_attack = new Capacity("attack",-1);
	Capacity *capa_beast_attackCount = new Capacity("attackCount",-1);
	Capacity *capa_beast_attackCountMax = new Capacity("attackCountMax",-1);
	Capacity *capa_beast_effect1 = new Capacity("effect",5);
	Capacity *capa_beast_effect2 = new Capacity("effect",4);

	capa_beast_hp->setActive(true);
	capa_beast_hpMax->setActive(true);
	capa_beast_attack->setActive(true);
	capa_beast_attackCount->setActive(true);
	capa_beast_attackCountMax->setActive(true);
	capa_beast_effect1->setActive(true);
	capa_beast_effect2->setActive(true);
	capa_beast_hp->setEffect(beast_hp);
	capa_beast_hpMax->setEffect(beast_hpMax);
	capa_beast_attack->setEffect(beast_attack);
	capa_beast_attackCount->setEffect(beast_attackCount);
	capa_beast_attackCountMax->setEffect(beast_attackCountMax);
	capa_beast_effect1->setEffect(beast_effect1);
	capa_beast_effect2->setEffect(beast_effect2);

	beast->addCapacity(capa_beast_hp);
	beast->addCapacity(capa_beast_hpMax);
	beast->addCapacity(capa_beast_attack);
	beast->addCapacity(capa_beast_attackCount);
	beast->addCapacity(capa_beast_attackCountMax);
	beast->addCapacity(capa_beast_effect1);
	beast->addCapacity(capa_beast_effect2);

	beast->calculateCost();
	printAllCapa(beast,"beast");

/*Hero*//*Hero*//*Hero*//*Hero*//*Hero*//*Hero*//*Hero*//*Hero*/
	Effect *hero_hp = new Effect("hp","none",5);
	Effect *hero_hpMax = new Effect("hpMax","none",7);
	Effect *hero_attack = new Effect("attack","none",5);
	Effect *hero_attackCount = new Effect("attackCount","none",0);
	Effect *hero_attackCountMax = new Effect("attackCountMax","none",1);
	Effect *hero_shards = new Effect("shards","none",3);
	Effect *hero_shardsMax = new Effect("shardsMax","none",7);

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

	printAllCapa(hero,"hero");

/*Spell*//*Spell*//*Spell*//*Spell*//*Spell*//*Spell*//*Spell*/
	Effect *damageeffect = new Effect("damage","none",6);
	Capacity *capa = new Capacity("damage",0);
	capa->setActive(true);
	capa->setEffect(damageeffect);
	spell->addCapacity(capa);

	spell->calculateCost();
	printAllCapa(spell,"spell");


/*=================================etape  4=========================================*/
/**/
	printEtape(": Modification on shards (into hero class)");

	hero->increaseShards(1);
	printCapa(hero,"shards","hero");
	hero->decreaseShards(1);
	printCapa(hero,"shards","hero");
	hero->increaseMaxShards(1);
	printCapa(hero,"shardsMax","hero, increase shardsMax");
	hero->decreaseMaxShards(1);
	printCapa(hero,"shardsMax","hero, decrease shardsMax");

	hero->increaseShards(1);
	printCapa(hero,"shards","hero, increase shards");
	hero->increaseShards(1);
	printCapa(hero,"shards","hero, increase shards");
	hero->increaseShards(1);
	printCapa(hero,"shards","hero, increase shards");
	hero->increaseShards(1);
	printCapa(hero,"shards","hero, increase shards");
	hero->increaseShards(1);
	printCapa(hero,"shards","hero, increase shards");
	hero->increaseShards(1);
	printCapa(hero,"shards","hero, increase shards");

/*=================================etape  5=========================================*/
/**/
	printEtape(": Modification on creature (manipulation on beast)");

	printIsAlive(beast);
	printCanAttack(beast);

	beast->increaseAttackCount();
	printCapa(beast,"attackCount","beast, increase attackcount");
	beast->increaseAttackCount();
	printCapa(beast,"attackCount","beast, increase attackcount");
	beast->resetAttackCount();
	printCapa(beast,"attackCount","beast, reset attackcount");

	beast->takeDamage(2);
	printCapa(beast,"hp","beast, take 2 damage");
	beast->heal(1);
	printCapa(beast,"hp","beast, heal 1 HP");
	beast->heal(1);
	printCapa(beast,"hp","beast, heal 1 HP");
	beast->heal(1);
	printCapa(beast,"hp","beast, heal 1 HP");

	beast->increaseMaxHP(1);
	printCapa(beast,"hpMax","beast, increase hpMax");
	beast->decreaseMaxHP(1);
	printCapa(beast,"hpMax","beast, decrease hpMax");

/*=================================etape  6=========================================*/
/**/
	printEtape(": Modification on Card");

	std::cout << "getTotal de 'effect': " << beast->getTotal("effect") << std::endl;

	beast->decreaseAllDurabilty();
	printAllCapa(beast,"beast");

/*=================================etape  5=========================================*/

	printEtape(": End of the test, all tests are succesfull for the science !");
	return 0;
}