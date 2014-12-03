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

#include "../../utils/tool.inc"

#define NUMBER 10

static unsigned int etape = 1;

/*for (it1=mylist.begin(); it1!=mylist.end(); ++it1)
    std::cout << ' ' << *it1;*/


void printBoard(Board *board){

	std::cout << "Board: " << std::endl;
	for(int i = 0; i < board->getSize(); i++){
		std::cout <<	"position: " << i << ", ";
		std::cout <<	" F: " << board->getCardX(i)->getStrength();
		std::cout <<	" E: " << board->getCardX(i)->getLife() << std::endl;
	} 
	std::cout << std::endl;
}

void printCard(Card *card,unsigned int max){

	std::cout << "Card: " << std::endl;
	for(int i = 0; i < max; i++){
		std::cout <<	" Card[" << i << "] = ";
		std::cout <<	" F: " << card[i].getStrength();
		std::cout <<	" E: " << card[i].getLife() << std::endl;
	} 
}

int main(int argc, char **argv){


/*Instance of some card, and three board: hand, battleField and deck*/
	Card *card;

	card = (Card*)malloc(NUMBER*sizeof(Card));

	Board *hand = new Board();
	Board *battleField = new Board();
	Board *deck = new Board();

	std::cout << std::endl;
	std::cout << etape << ": Instanciation of cards, hand, battleField and deck donne" << std::endl;

/*Initialisation of all cards*/
	for(size_t i = 0; i < NUMBER; i++){
		card[i].setStrength(i);
		card[i].setLife(i);
	}

	printCard(card,NUMBER);

	std::cout << std::endl;
	etape++;
	std::cout << etape << ": Initialisation of all cards done" << std::endl;
/*Set the max size of all board*/
	deck->setMaxSize(NUMBER);
	hand->setMaxSize(NUMBER);
	battleField->setMaxSize(7);


	std::cout << std::endl;
	etape++;
	std::cout <<  etape << ": Set max size of all board done" << std::endl;
	std::cout << " Max size of deck: " << deck->getMaxSize() << " hand: " << hand->getMaxSize() 
		 << " battleField: " << battleField->getMaxSize() << std::endl;
	std::cout << " Size of deck: " << deck->getSize() << " hand: " << hand->getSize() 
		 << " battleField: " << battleField->getSize() << std::endl;

/*I try to put a card in some invalides positions*/
	hand->addCardX(&card[6],6);
	hand->addCardX(&card[0],12);
	

/*I put all cards in the deck*/

	for(size_t i = 0; i < NUMBER; i++){
		deck->addCardX(&card[i],i);
	}

	std::cout << std::endl;
	etape++;
	std::cout <<  etape << ": Fill the deck with all cards" << std::endl;
	printBoard(deck);



/*	Il manque getCard, takeCard, deletCard, getSize, addListCard et destruction, il manque aussi la création d'une liste avec une liste de cartes
	Il manque aussi le fait que l'on travail avec des RegulateBoard & des StackBoard
			*/

	std::cout << std::endl;
	etape++;
	std::cout << etape << ": End of the test, all tests are succesfull for the science !" << std::endl;
	return 0;
}

/*
+	Board();
	Board(std::list<Card> *listCard);
+	virtual Card * getCardX(unsigned int x);
	Card * takeCardX(unsigned int x);
	virtual void deletCardX(unsigned int x);
+	unsigned int getSize();
+	unsigned int getMaxSize();
+	void setMaxSize(unsigned int size);
+	virtual void addCardX(Card *card,unsigned int x);
	virtual void addListCardX(std::list<Card> *listCard,unsigned int x);
	bool isFull();
	virtual ~Board();
protected:
	std::list<*Card>	listCard;
*/