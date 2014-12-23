#pragma once
#include "Board.h"
class StackedBoard :
	public Board
{
public:
	/**
	* Constructor which puts listCard to NULL.
	*/
	StackedBoard() : Board() {}

		/**
		* Create a board and initialize it with the pointer of listCard.
		* @param std::list<Card> *listCard pointer of a list of card.
		*/
	StackedBoard(std::list<Card*> *listCard) : Board(listCard){}

	/**
	* Get the card which is at the Xth position.
	* @param unsigned int x position of the wanted card.
	* @return Card the pointer of the card.
	*/
	iCard * getCardX(unsigned int x);

	/**
	* Take the card which is at the Xth position and erase it of the deck.
	* @param unsigned int x position of the wanted card.
	* @return Card the pointer of the card.
	*/
	iCard * takeCardX(unsigned int x);

	/**
	* Delete the card which is at the Xth position.
	* @param unsigned int x position of the card to be deleted.
	*/
	void deleteCardX(unsigned int x);

	/**
	* Return the size of the list.
	* @return unsigned int the size.
	*/
	unsigned int getSize();

	/**
	* Return the maximum size of the list.
	* @return unsigned int the maximum size.
	*/
	unsigned int getMaxSize();

	/**
	* Set the maximum size of the list to the value size.
	* @param unsigned int size.
	*/
	void setMaxSize(unsigned int size);

	/**
	* Add a card at the Xth position of a board.
	* @param Card *card pointer of the target card, unsigned int x wanted position.
	*/
	void addCardX(iCard *card, unsigned int x);

	/**
	* Add a list of cards at the Xth position of a board.
	* @param std::list<Card> *listCard pointer of the list of cards, unsigned int x wanted position.
	*/
	void addCardX(std::list<iCard*> *listcard, unsigned int x);

	/**
	* Return true if the list is full (like an egg), else 0.
	* @param std::list<Card> *listCard pointer of the list of cards.
	* @return bool.
	*/
	bool isFull();

	/**
	* Destructor.
	*/
	~StackedBoard();
};


