#include "Card.h"
#include "../../Board/Board.h"
#include <iostream>
#include <string>
#include <cstdlib>

#define NUMBER 10


void printBoard(Board *board){

	std::cout << "Board: " << std::endl;
	for(int i = 0; i < board->getSize(); i++){
		std::cout <<	" " << board->getCardX(i);
	} 

	std::cout << std::endl;
	std::cout << std::endl;
}


int main(int argc, char **argv){


/*Instance of some card, and three board: hand, battleField and deck*/
	Card *card;

	card = (Card*)malloc(NUMBER*sizeof(Card));

	Board *hand = new Board();
	Board *battleField = new Board();
	Board *deck = new Board();

	std::cout << "1: Instaciation of cards, hand, battleField and deck donne" << std::endl;

/*Initialisation of all cards*/
	for(size_t i = 0; i < NUMBER; i++){
		card[i].setStrength(i);
		card[i].setLife(i);
	}

	std::cout << "2: Initialisation of all cards donne" << std::endl;
/*Set the max size of all board*/
	deck->setMaxSize(NUMBER);
	hand->setMaxSize(NUMBER);
	battleField->setMaxSize(7);

	std::cout << "3: Set max size of all board donne" << std::endl;
	std::cout << " Max size of deck: " << deck->getMaxSize() << " hand: " << hand->getMaxSize() 
		 << " battleField: " << battleField->getMaxSize() << std::endl;

/*I try to put a card in some invalides positions*/
//	hand.addCardX(card[6],6);
//	hand.addCardX(card[0],12);


/*I put all cards in the deck*/
	/*for(size_t i = 0; i < NUMBER; i++){
		(deck+i)->addCardX((card+i),(unsigned int)i);
	}*/

	std::cout << "4: Fill the deck with all card" << std::endl;
	printBoard(deck);



/*	Il manque getCard, takeCard, deletCard, getSize, addListCard et destruction, il manque aussi la création d'une liste avec une liste de cartes
	Il manque aussi le fait que l'on travail avec des RegulateBoard & des StackBoard
			*/



	std::cout << "5: End of the test, all tests are a succesfull for the science !" << std::endl;
	return 0;
}

/*
Board();
Board(std::list<Card> *listCard);
virtual Card * getCardX(unsigned int x);
Card * takeCardX(unsigned int x);
virtual void deletCardX(unsigned int x);
unsigned int getSize();
unsigned int getMaxSize();
void setMaxSize(unsigned int size);
virtual void addCardX(Card *card,unsigned int x);
virtual void addListCardX(std::list<Card> *listCard,unsigned int x);
bool isFull(std::list<Card> *listCard);
virtual ~Board();
protected:
	std::list<*Card>	listCard;
*/