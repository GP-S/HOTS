#include "../../Card/Card.h"
#include "../../Card/Beast.h"
#include "../../Card/Capacity.h"
#include "../../Card/Creature.h"
#include "../../Card/Effect.h"
#include "../../Card/Player.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <string>

#include "../../utils/tool.inc"

#define NUMBER 10

static unsigned int etape = 0;
std::string name = "alpha";
std::string type = "beta";
std::string race = "gamma";


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
		std::cout <<	" cardType: " << beast[i].getCardType();
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
		std::cout <<	" cardType: " << creature[i].getCardType();
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
		std::cout <<	" cardType: " << card[i].getCardType();
		std::cout <<	" cost: " << card[i].getCost() << std::endl;
	} 

}

/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){


/*==================================================================================*/
/*I Instance some card, creature, beast*/
	printEtape(": Instanciation of cards, creatures and beasts");	// etape 1
	Card *card;
	Creature *creature;
	Beast *beast;

	card = (Card*)malloc(NUMBER*sizeof(Card));
	creature = (Creature*)malloc(NUMBER*sizeof(Creature));
	beast = (Beast*)malloc(NUMBER*sizeof(Beast));

/*==================================================================================*/
/*I Initialise some card, creature, beast*/
	printEtape(": Intialisation of cards, creatures and beasts");	// etape 2

	for(size_t i = 0; i < NUMBER; i++){

		card[i].setName(name++);
		card[i].setCardType(type++);
		card[i].calculateCost();
	}

	printCard(card,NUMBER);

	for(size_t i = 0; i < NUMBER; i++){

		beast[i].setName(name++);
		beast[i].setCardType(type++);
		beast[i].setHp(i+1);
		beast[i].setBaseAttack(i);
		beast[i].setRace(race++);
		beast[i].calculateCost();
	}

	printBeast(beast,NUMBER);

	for(size_t i = 0; i < NUMBER; i++){

		creature[i].setName(name++);
		creature[i].setCardType(type++);
		creature[i].setHp(i+1);
		creature[i].setBaseAttack(i);
		creature[i].calculateCost();
	}

	printCreature(creature,NUMBER);


/*==================================================================================*/
/*I try to get all attribute of all class*/
	printEtape(": Test all getteur");	// etape 3






/*==================================================================================*/
/*	 destruction, il manque aussi la création d'une liste avec une liste de cartes
	Il manque aussi le fait que l'on travail avec des RegulatedBoard & des StackBoard
			*/

	printEtape(": End of the test, all tests are succesfull for the science !");	// etape 10
	return 0;
}

/*Done

###Beast();
###std::string getRace();
###void setRace(std::string race);

###Creature();
###void setHp(int hp);
###void setBaseAttack(int attack);
###int getHp();
###int getBaseAttack();

###Card();
###int	getCost();	
###
###
###std::string	getName();
###std::string	getType();
###void calculateCost();


*/

/* To do


Beast(std::string race);
~Beast();
bool isAlive();

protected:
	std::string race;





Creature(std::string name,int hp,int attack);
~Creature();
virtual bool isAlive();
void attack(Creature* target);
void resetAttackCount();
bool canAttack();
void takeDamage(unsigned int damage);
void heal(unsigned int heal);
void increaseMaxHP(unsigned int modifier);
void decreaseMaxHP(unsigned int modifier);       
void increaseAttackCount(); 
protected:
   	int hp;
   	int	baseAttack;
   	int attackCount;




Card(std::string name, std::string cardType);
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