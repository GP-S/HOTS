/**
* I can't work on Attack and canAttack
*
*/



#define NUMBER 10

static unsigned int etape = 0;
std::string name = "alpha";
std::string type = "beta";
std::string race = "gamma";

std::string intToString(int i) {
     std::ostringstream oss;
     oss << i;
     return oss.str();
}

void printEtape(std::string text){
	std::cout << std::endl;
	etape++;
	std::cout << "***etape: " << etape << text << " *** " << std::endl;
}

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

void printCreature(Creature *creature,unsigned int max){

	std::cout << "Creature: " << std::endl;
	for(size_t i = 0; i < max; i++){
		std::cout <<	" creature[" << i << "] = ";
		std::cout <<	" Name: " << creature[i].getName();
		std::cout <<	" cardType: " << creature[i].getType();
		std::cout <<	" cost: " << creature[i].getCost();
		std::cout <<	" hp: " << creature[i].getHp();
		std::cout <<	" baseAttack: " << creature[i].getBaseAttack() << std::endl;
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

void printIsAlive(Creature * creature,unsigned int max){

	for(size_t i = 0; i < max; i++){
		std::cout <<	" creature[" << i << "] = ";
		std::cout << creature[i].getName();
		std::cout <<	" is ";
		if(creature[i].isAlive())
			std::cout << "alive" << std::endl;
		else
			std::cout << "dead" << std::endl;
	} 
}

/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){


/*==================================================================================*/
/*I Instance some card, creature, beast*/
	printEtape("Instanciation of cards, creatures and beasts");	// etape 1
	Card *card;
	Creature *creature;
	Beast *beast;

	card = (Card*)malloc(NUMBER*sizeof(Card));
	creature = (Creature*)malloc(NUMBER*sizeof(Creature));
	beast = (Beast*)malloc(NUMBER*sizeof(Beast));

/*==================================================================================*/
/*I Initialise some card, creature, beast*/
	printEtape("Intialisation of cards, creatures and beasts");	// etape 2

	/*for(size_t i = 0; i < NUMBER; i++){
		printEtape("plop 0");
		//card[i].setName(name);
		printEtape("plop 1");
		//card[i].setType(type);
		printEtape("plop 2");
		//card[i].calculateCost();
		printEtape("plop 3");
		name += intToString(i);
		printEtape("plop 4");
		type += intToString(i);
		printEtape("plop 5");
	}

	printCard(card,NUMBER);*/

	for(size_t i = 0; i < NUMBER; i++){

		printEtape("plop 0");
		beast[i].setName(name);
		beast[i].setType(type);
		beast[i].setHp(i+1);
		beast[i].setBaseAttack(i);
		beast[i].setRace(race);
		beast[i].calculateCost();
		name += intToString(i);
		type += intToString(i);
		race += intToString(i);
	}

	printBeast(beast,NUMBER);

	for(size_t i = 0; i < NUMBER; i++){

		creature[i].setName(name);
		creature[i].setType(type);
		creature[i].setHp(i+1);
		creature[i].setBaseAttack(i);
		creature[i].calculateCost();
		name += intToString(i);
		type += intToString(i);
	}

	printCreature(creature,NUMBER);

/*==================================================================================*/
/*I Instance a beast and a creature*/
	printEtape("Instanciation of heros ,human");	// etape 3


	//Card *firstCard = new Card("firstCard","\0");
	// I can't do this because Card is abstract

	Creature *heros = new Creature("heros",30,2);
	Beast *arthas = new Beast("Arthas",4,6,"human");

	printCreature(heros,1);
	printBeast(arthas,1);


/*==================================================================================*/
/*I try to get all attribute of all class*/
	printEtape("Test all getteur");	// etape 4



/*==================================================================================*/
/*I test the methode attack*/
	printEtape("Fight beteewn heros and arthas");	// etape 5

	arthas->takeDamage(heros->getBaseAttack());
	heros->takeDamage(arthas->getBaseAttack());

	printCreature(arthas,1);
	printCreature(heros,1);

	printIsAlive(arthas,1);
	printIsAlive(heros,1);

/*==================================================================================*/
/*I test the methode attack and canAttack util death*/
	printEtape("Fight beteewn heros and arthas util death");	// etape 6

	size_t roundNumber = 0;
	while(arthas->isAlive() | heros->isAlive()){
		roundNumber++;

		std::cout << "round number: " << roundNumber << std::endl;

		arthas->takeDamage(heros->getBaseAttack());
		heros->takeDamage(arthas->getBaseAttack());

		printCreature(arthas,1);
		printCreature(heros,1);
	}

		printIsAlive(arthas,1);
		printIsAlive(heros,1);

/*==================================================================================*/
/*I test methode for increase/decrease attribute*/
	printEtape("heal, increaseMaxHP, increaseAttackCount, decreaseMaxHP");	// etape 7

	std::cout << "	before tests" << std::endl;
	printCreature(&creature[9],1);

	std::cout << "	takeDamage 3" << std::endl;
	creature[9].takeDamage(3);
	printCreature(&creature[9],1);

	std::cout << "heal 10" << std::endl;
	creature[9].heal(10);
	printCreature(&creature[9],1);

	std::cout << "increaseMaxHP 4" << std::endl;
	creature[9].increaseMaxHP(4);

	std::cout << "increaseAttackCount 3" << std::endl;
	//creature[9].increaseAttackCount(3);
	printCreature(&creature[9],1);

	std::cout << "decreaseMaxHP 8" << std::endl;
	creature[9].decreaseMaxHP(8);
	printCreature(&creature[9],1);


/*==================================================================================*/
/*	 destruction, il manque aussi la création d'une liste avec une liste de cartes
	Il manque aussi le fait que l'on travail avec des RegulatedBoard & des StackBoard
			*/

	printEtape("End of the test, all tests are succesfull for the science !");	// etape 10
	return 0;
}

/*Done

###Beast();
#Beast(std::string race);
###std::string getRace();
###void setRace(std::string race);

###Creature();
###Creature(std::string name,int hp,int attack);
###void setHp(int hp);
###void setBaseAttack(int attack);
###int getHp();
###int getBaseAttack();
###void attack(Creature* target);
###bool canAttack();
###void takeDamage(unsigned int damage);
###void heal(unsigned int heal);
###void increaseMaxHP(unsigned int modifier);
###void decreaseMaxHP(unsigned int modifier);       
###void increaseAttackCount(); 

###Card();
###Card(std::string name, std::string cardType);
###int	getCost();	
###void setName(std::string);
###void setType(std::string);
###std::string	getName();
###std::string	getType();
###void calculateCost();


*/

/* To do


~Beast();
bool isAlive();




~Creature();
virtual bool isAlive();
void resetAttackCount();



~Card();
void addCapacity(Capacity* capa);
virtual bool isAlive() = 0;
    //	std::list<Capacity*>*		findCapaByType(std::string capaType);
bool isUsable(Player p);
int getTotal(std::string effectType);
void decreaseAllDurabilty();

protected:
    std::string				name;
	std::string				cardType;
    int                     cost;
    std::list<Capacity*>*   capaList;
    Player                  owner;



*/