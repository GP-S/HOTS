#ifndef REGULATEDBOARD_H
#define REGULATEDBOARD_H

#include "Board.h"

/**
* Class of RegulatedBoard is: .
* @author Nicolas Léger
* @author Francois Denquin
**/


class RegulatedBoard : public Board
{

protected: 
	std::list<iCard*> *cardByArrivalTime;

public:
  
  	/** 
	* Constructor which puts listCard and cardByArrivalTime to NULL. 
	*/
	RegulatedBoard();

	/** 
	* Create a board and initialize it with the pointer of listCard.  
	* @param std::list<Card> *listCard pointer of a list of cards.
	*/
	RegulatedBoard(std::list<iCard*> *listCard);

	/** 
	* Take the card which is at the Xth position and erase it of the deck.
	* @param unsigned int x position of the wanted card.
	* @return Card the pointer of the card.
	*/
	iCard* takeCardX(unsigned int x);

	/**
	 * Delete the card which is at the Xth position.
	 * @param unsigned int x position of the card to be deleted.
	 */
	void deletCardX(unsigned int x);

	/**
 	* Add a card at the Xth position of a board.
 	* @param Card *card pointer of the target card, unsigned int x wanted position.
 	*/
	void addCardX(iCard *card,unsigned int x);

	/**
	* Add a list of cards at the Xth position of a board and at the end of its regulated list.
	* @param std::list<Card> *listCard pointer of the list of cards, unsigned int x wanted position.
	*/
	void addCardX(std::list<iCard*> *listcard, unsigned int x);
	/**
	 * Return the position in the CardArrivalByTime listCard.
	 * @param Card *card pointer of card.
	 * @return unsigned int.
	 */
	unsigned int CardArrivalByTime(iCard *card);

	/**
 	* Destructor.
 	*/
	~RegulatedBoard();
  
};  


#endif //REGULATEDBOARD_H
