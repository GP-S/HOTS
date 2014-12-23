#ifndef REGULATEDBOARD_H
#define REGULATEDBOARD_H

#include "Board.h"

/**
 * 
 * Write the functions in StackBoard.cpp, then write here the commentaries
 * 
 */


class RegulatedBoard : public Board
{

protected: 
	std::list<Card*> *cardByArrivalTime;

public:
  
  	/** 
	* Constructor which puts listCard and cardByArrivalTime to NULL. 
	*/
	RegulatedBoard();

	/** 
	* Create a board and initialize it with the pointer of listCard.  
	* @param std::list<Card> *listCard pointer of a list of card.
	*/
	RegulatedBoard(std::list<Card*> *listCard);

	/** 
	* Take the card which is at the Xth position and erase it of the deck.
	* @param unsigned int x position of the wanted card.
	* @return Card the pointer of the card.
	*/
	Card* takeCardX(unsigned int x);

	/**
	 * Delete the card which is at the Xth position.
	 * @param unsigned int x position of the card to be deleted.
	 */
	void deletCardX(unsigned int x);

	/**
 	* Add a card at the Xth position of a board.
 	* @param Card *card pointer of the target card, unsigned int x wanted position.
 	*/
	void addCardX(Card *card,unsigned int x);

	/**
	* Add a list of cards at the Xth position of a board and at the ed of its regulated list.
	* @param std::list<Card> *listCard pointer of the list of cards, unsigned int x wanted position.
	*/
	void addCardX(std::list<Card*> *listcard, unsigned int x);
	/**
	 * Return the position in the CardArrivalByTime listCard.
	 * @param Card *card pointer of card.
	 * @return unsigned int.
	 */
	unsigned int CardArrivalByTime(Card *card);

	/**
 	* Destructor.
 	*/
	~RegulatedBoard();
  
};  


#endif //REGULATEDBOARD_H
