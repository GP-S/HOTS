#include "Board.h"
#include "Card.h"
#include <iostream>
#include <string>

#define NOMBER 10

unsing namespace std;

void printBoard(Board *board){

	cout << "Board: " << endl;
	for(int i = 0; i < board->getSize(); i++){
		cout <<	" " << board->getCardX(i) << end;
	} 

	cout << endl;

}


int main(int argc, char **argv){


/**Instance of some card, and three board: hand, battleField and deck*/
	Card *card;

	card = (Card)malloc(NOMBER*sizeof(Card));
	Board hand = new Board();
	Board battleField = new Board();
	Board deck = new Board();

	cout << "1: Instaciation of cards, hand, battleField and deck donne" << endl;

/*Initialisation of all cards*/
	for(int i = 0; i < NOMBER; i++){
		card[i].setStrength(i);
		card[i].setLife(i);
	}

	cout << "2: Initialisation of all cards donne" << endl;
/*Set the max size of all board*/
	deck.setMaxSize(NOMBER);
	hand.setMaxSize(NOMBER);
	battleField.setMaxSize(7);

	cout << "3: Set max size of all board donne" << endl;
	cout << "	Max size of deck: " << deck.getMaxSize() << " hand: " << hand.getMaxSize() 
		 << " battleField: " << battleField.getMaxSize() << endl;

/*I try to put a card in some invalides positions*/
	hand.addCardX(card[6],6);
	hand.addCardX(card[0],12);


/*I put all cards in the deck*/
	for(int i = 0; i < NOMBER; i++){
		deck[i].addCardX(card[i],i);
	}

	printBoard(&deck);

/*	Il manque getCard, takeCard, deletCard, getSize, addListCard et destruction, il manque aussi la création d'une liste avec une liste de cartes
	Il manque aussi le fait que l'on travail avec des RegulateBoard & des StackBoard
			*/



	cout << "X: End of the test, all tests are a succesfull for the science !" << endl;
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