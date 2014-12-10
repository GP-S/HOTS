/**
*
*	g++ Board_Test.cpp ../../Board/Board.cpp Card.cpp  -I ./
*	./a.out
*/


#include "Card.h"
#include "../../Board/Board.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <string>

#include "../../utils/tool.inc"

#define NUMBER 10

static unsigned int etape = 0;


void printEtape(std::string text){
	std::cout << std::endl;
	etape++;
	std::cout << "***etape: " << etape << text << " *** " << std::endl;
}

void printBoard(Board *board, std::string name){

	std::cout << "Board " << name << ": " << std::endl;
	for(size_t i = 0; i < board->getSize(); i++){
		std::cout <<	"position: " << i << ", ";
		std::cout <<	" F: " << board->getCardX(i)->getStrength();
		std::cout <<	" E: " << board->getCardX(i)->getLife() << std::endl;
	} 
	std::cout << std::endl;
}

void printCard(Card *card,unsigned int max){

	std::cout << "Card: " << std::endl;
	for(size_t i = 0; i < max; i++){
		std::cout <<	" Card[" << i << "] = ";
		std::cout <<	" F: " << card[i].getStrength();
		std::cout <<	" E: " << card[i].getLife() << std::endl;
	} 
}

void printSizeBoard(Board *board, std::string name){
	std::cout << "Board " << name << " maxSize: " << board->getMaxSize() << " Size: " << board->getSize() << std::endl;
}

/*==================================================================================*/
/*===================================MAIN===========================================*/
/*==================================================================================*/

int main(int argc, char **argv){


/*Instance of some card, and three board: hand, battlefield and deck*/
	Card *card;
	Card *tmpCard;

	card = (Card*)malloc(NUMBER*sizeof(Card));
	tmpCard = (Card*)malloc(NUMBER*sizeof(Card));

	Board *hand = new Board();
	Board *battlefield = new Board();
	Board *deck = new Board();

	printEtape(": Instanciation of cards, hand, battlefield and deck donne");	// etape 1

/*Initialisation of all cards*/
	for(size_t i = 0; i < NUMBER; i++){
		card[i].setStrength(i);
		card[i].setLife(i);
	}

	printCard(card,NUMBER);

	printEtape(": Initialisation of all cards done");	// etape 2
/*Set the max size of all board*/
	deck->setMaxSize(NUMBER);
	hand->setMaxSize(NUMBER);
	battlefield->setMaxSize(7);


	printEtape(": Set max size of all board done");	// etape 3

	printSizeBoard(deck,"deck");
	printSizeBoard(hand,"hand");
	printSizeBoard(battlefield,"battlefield");

/*I try to put a card in some invalides positions*/
	//hand->addCardX(&card[6],6);
	//hand->addCardX(&card[0],12);
	

/*I put all cards in the deck*/

	for(size_t i = 0; i < NUMBER; i++){
		if(!deck->isFull())
			deck->addCardX(&card[i],i);
		else
			std::cout << "The board " << "deck" << " is full !" << std::endl;
		
	}

	printEtape(": Fill the deck with all cards");	// etape 4
	printBoard(deck,"deck");

/**/

	for(size_t i = 0; i < NUMBER; i++){
		tmpCard[i] = *deck->getCardX(i);
	}

	printEtape(": getCardX");	// etape 5
	printCard(tmpCard,NUMBER);

/*I delete the first Card of deck*/

	deck->deleteCardX(0);

	printEtape(": Delete the first card of deck");	// etape 6
	printSizeBoard(deck,"deck");
	printBoard(deck,"deck");

/*I add a card at the first position of deck*/

	deck->addCardX(&card[0],0);

	printEtape(": Add a card at the top of deck");	// etape 7
	printSizeBoard(deck,"deck");
	printBoard(deck,"deck");

/*I take all cards from deck and I put them into hand*/

	printEtape(": Take all cards from deck and put them into hand");	// etape 8
	for(size_t i = 0; i < NUMBER; i++){
		tmpCard[i] = *deck->takeCardX(0);

		if(!hand->isFull())
			hand->addCardX(&tmpCard[i],i);
		else
			std::cout << "The board " << "hand" << " is full !" << std::endl;

		std::cout << "loop number: " << i << std::endl;
		printSizeBoard(deck,"deck");
		//printBoard(deck,"deck");
		printSizeBoard(hand,"hand");
		//printBoard(hand,"hand");
	}


/*I take all cards from hand and I put them into battlefield, if i can't place it on battle, I keep it in hand*/

	printEtape(": Take all cards from hand and put them into battlefield");	// etape 9
	for(size_t i = 0; i < NUMBER; i++){
		tmpCard[i] = *hand->takeCardX(0);

		std::cout << "loop number: " << i << std::endl;

		if(!battlefield->isFull())
			battlefield->addCardX(&tmpCard[i],i);
		else{
			std::cout << "The board " << "battlefield" << " is full !" << std::endl;
			hand->addCardX(&tmpCard[i],0);
		}
		printSizeBoard(hand,"hand       ");
		//printBoard(hand,"hand");
		printSizeBoard(battlefield,"battlefield");
		//printBoard(battlefield,"battlefield");
	}

/*I add the list of cards to deck*/

	printEtape(": add list of cards to deck");	// etape 10

	std::list<Card*> *listCard = new std::list<Card*>();

	std::list<Card*>::iterator it = listCard->begin();
	for(size_t i = 0; i < NUMBER; i++){
		listCard->insert(it++, &card[i]);
	}

	printCard(card,NUMBER);
	foreach(std::list<Card*>, listCard, it){
		printCard(*it,1);
		std::cout << "hello" << std::endl;
	}

	deck->addListCardX(listCard,0);

	printSizeBoard(deck,"deck");
	printBoard(deck,"deck");


/*	Il manque  addListCard et destruction, il manque aussi la création d'une liste avec une liste de cartes
	Il manque aussi le fait que l'on travail avec des RegulateBoard & des StackBoard
			*/

	printEtape(": End of the test, all tests are succesfull for the science !");	// etape 10
	return 0;
}
