#include "Card_Test.h"

#define NUMBER 5

static unsigned int etape = 0;
static const std::string cardName[NUMBER] = {"alpha","fire","dafuck","beta","omega"};
static const std::string cardType[NUMBER] = {"beast","spell","card_dafuck","creature","hero"};
static const std::string cardRace[NUMBER] = {"human","robot","none","none","none"};




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

/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){


/*=================================etape  1=========================================*/
/*I Instance all diferent Card*/
	printEtape(": Instanciation of all Cards type");
	Card *card;
	Spell *spell;
	Creature *creature;
	Hero *hero;
	Beast *beast;

	Card *anotherCard = new Card("card","card_dafuck");
	Spell *anotherSpell = new Spell("Lightning bolt");
	Creature *anotherCreature = new Creature("creature",2,3);
	Hero *anotherHero = new Hero("Arthas",30,0);
	Beast *anotherBeast = new Beast("Nicolas",1,0,"human");


/*=================================etape  2=========================================*/
/*I Initialise all Cards*/
	printEtape(": Intialisation of cards");

	/*card->setName(cardName[2]);
	card->setType(cardType[2]);
	card->calculateCost();

	printCard(card);*/

	(Card*)beast->setName("0");
	// beast->setType(cardType[0]);
	// beast->setHp(5);
	// beast->setBaseAttack(1);
	// beast->setRace(cardRace[0]);
	// beast->calculateCost();
	printEtape(": Intialisation of cards");	
	printBeast(beast);
	printEtape(": Intialisation of cards");
	// creature->setName(cardName[3]);
	// creature->setType(cardType[3]);
	// creature->setHp(1);
	// creature->setBaseAttack(1);
	// creature->calculateCost();
	
	// printCreature(creature);

	// hero->setName(cardName[4]);
	hero->setType(cardType[4]);
	// hero->setHp(30);
	// hero->setBaseAttack(0);
	// hero->calculateCost();
	
	printHero(hero);
	printEtape(": Intialisation of cards");
	// spell->setName(cardName[1]);
	// spell->setType(cardType[1]);
	// spell->calculateCost();

	// printSpell(spell);


	printCard(anotherCard);
	printBeast(anotherBeast);
	printCreature(anotherCreature);
	printHero(anotherHero);
	printSpell(anotherSpell);


/*=================================etape  3=========================================*/
/*I test the methode attack*/
	printEtape(": Not implemented yet");


/*=================================etape  4=========================================*/

	printEtape(": End of the test, all tests are succesfull for the science !");
	return 0;
}


/*=================================Beast=========================================*/
/*

        Beast();
		Beast(std::string name,int hp,int attack,std::string race);
        ~Beast();
		std::string getRace();
		void setRace(std::string race);

		
    protected:

    	std::string race;
*/
/*=================================Hero=========================================*/
/*

		Hero();
		Hero(std::string name,int hp,int attack);
        ~Hero();
        void    increaseShards(unsigned int modifier);
        void    decreaseShards(unsigned int modifier);
        void    increaseMaxShards(unsigned int modifier);
        void    decreaseMaxShards(unsigned int modifier);

    protected:
*/
/*=================================Creature=========================================*/
/*

        Creature();
		Creature(std::string name,int hp,int attack);
        ~Creature();
		virtual bool isAlive();
		virtual int getHp();
		virtual int getBaseAttack();
		virtual void setHp(int hp);
		virtual void setBaseAttack(int attack);
        virtual void resetAttackCount();
        virtual bool canAttack();
        virtual void takeDamage(unsigned int damage);
        virtual void heal(unsigned int heal);
        virtual void increaseMaxHP(unsigned int modifier);
        virtual void decreaseMaxHP(unsigned int modifier);
        virtual void increaseAttackCount(); 

    protected:

    	int hp;
    	int	baseAttack;
    	int attackCount;
*/
/*=================================Spell=========================================*/
/*

		Spell();
        Spell(std::string name);
        ~Spell();
        
    protected:

*/
/*=================================Card=========================================*/
/*
		Card();
    	Card(std::string name, std::string cardType);
    	~Card();								
    	int	getCost();
        void setType(std::string type);
        void setName(std::string name);
    	void calculateCost();
    	void addCapacity(iCapacity* capa);
    	std::string getName();
		std::list<Capacity*>* findCapaByType(std::string capaType);
    	std::string	getType();
        int getTotal(std::string effectType);
        void decreaseAllDurabilty();

    protected:
        std::string				name;
		std::string				cardType;
        int                     cost;
        std::list<Capacity*> *  capaList;
        Player*                 owner;
*/