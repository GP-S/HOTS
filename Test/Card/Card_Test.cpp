#include "Card_Test.h"

#define NUMBER 5
#define ALLCAPA 9

static unsigned int etape = 0;
static const std::string cardName[NUMBER] = {"alpha","fire","dafuck","beta","omega"};
static const std::string cardType[NUMBER] = {"beast","spell","card_dafuck","creature","hero"};
static const std::string cardRace[NUMBER] = {"human","robot","none","none","none"};
static const std::string capaName[ALLCAPA] = {	"attack","attackCount","attackCountMax",
												"damage","hp","hpMax","shards",
												"shardsMax","effect"
											 };



void printEtape(std::string text){
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

void printAllCapa(Card *card,std::string name){

	std::cout << "Print all capa of " << name << std::endl;

	for(size_t i = 0; i < ALLCAPA; i++){
		std::list<Capacity*>* capalist =  card->findCapaByType(capaName[i]);
		for(std::list<Capacity*>::iterator it = capalist->begin(); it != capalist->end();++it){
			printCapacity((*it));
		}
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

	Effect *hp = new Effect("hp","none",5);
	Effect *hpMax = new Effect("hpMax","none",7);
	Effect *attack = new Effect("attack","none",5);
	Effect *attackCount = new Effect("attackCount","none",0);
	Effect *attackCountMax = new Effect("attackCountMax","none",1);
	Effect *effect1 = new Effect("effect","none",1);
	Effect *effect2 = new Effect("effect","none",5);

	Capacity *capa_hp = new Capacity("hp",-1);
	Capacity *capa_hpMax = new Capacity("hpMax",-1);
	Capacity *capa_attack = new Capacity("attack",-1);
	Capacity *capa_attackCount = new Capacity("attackCount",-1);
	Capacity *capa_attackCountMax = new Capacity("attackCountMax",-1);
	Capacity *capa_effect1 = new Capacity("effect",5);
	Capacity *capa_effect2 = new Capacity("effect",4);

	capa_hp->setEffect(hp);
	capa_hpMax->setEffect(hpMax);
	capa_attack->setEffect(attack);
	capa_attackCount->setEffect(attackCount);
	capa_attackCountMax->setEffect(attackCountMax);
	capa_effect1->setEffect(effect1);
	capa_effect2->setEffect(effect2);

	beast->addCapacity(capa_hp);
	beast->addCapacity(capa_hpMax);
	beast->addCapacity(capa_attack);
	beast->addCapacity(capa_attackCount);
	beast->addCapacity(capa_attackCountMax);
	beast->addCapacity(capa_effect1);
	beast->addCapacity(capa_effect2);

	beast->calculateCost();
	printAllCapa(beast,"beast");

	Effect *shards = new Effect("shards","none",3);
	Effect *shardsMax = new Effect("shardsMax","none",7);
	
	Capacity *capa_shards = new Capacity("shards",-1);
	Capacity *capa_shardsMax = new Capacity("shardsMax",-1);

	hero->addCapacity(capa_hp);
	hero->addCapacity(capa_hpMax);
	hero->addCapacity(capa_attack);
	hero->addCapacity(capa_attackCount);
	hero->addCapacity(capa_attackCountMax);
	hero->addCapacity(capa_shards);
	hero->addCapacity(capa_shardsMax);

	hero->calculateCost();
	printAllCapa(hero,"hero");

	Effect *damageeffect = new Effect("damage","none",6);
	Capacity *capa = new Capacity("damage",0);
	capa->setEffect(damageeffect);
	spell->addCapacity(capa);


	spell->calculateCost();
	printAllCapa(spell,"spell");


/*=================================etape  4=========================================*/
/*I add some Capacity to beast, spell and hero*/
	printEtape(": Add capacity to beast,spell and hero");


/*=================================etape  5=========================================*/

	printEtape(": End of the test, all tests are succesfull for the science !");
	return 0;
}


/*=================================Beast=========================================*/
/*
        ~Beast();
*/
/*=================================Hero=========================================*/
/*
        ~Hero();
        void    increaseShards(unsigned int modifier);
        void    decreaseShards(unsigned int modifier);
        void    increaseMaxShards(unsigned int modifier);
        void    decreaseMaxShards(unsigned int modifier);

*/
/*=================================Creature=========================================*/
/*

        ~Creature();
		virtual bool isAlive();
        virtual void resetAttackCount();
        virtual bool canAttack();
        virtual void takeDamage(unsigned int damage);
        virtual void heal(unsigned int heal);
        virtual void increaseMaxHP(unsigned int modifier);
        virtual void decreaseMaxHP(unsigned int modifier);
        virtual void increaseAttackCount(); 


*/
/*=================================Spell=========================================*/
/*

        ~Spell();

*/
/*=================================Card=========================================*/
/*
    	~Card();								
    	int	getCost();
        int getTotal(std::string effectType);
        void decreaseAllDurabilty();

*/