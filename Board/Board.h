#ifndef BOARD_H
#define BOARD_H

#include <list>
#include "../Card/iCard.h"
#include "../Card/Card.h"
#include <iostream>
#include <string>
#include "iBoard.h"

/**
* The class Board is:
* @author Nicolas Léger
* @author François Denquin
*/
class Board : public iBoard
{
protected:
	std::list<iCard*> *listCard;
	unsigned int size_max;

public:
	
	/** 
	* Constructor which puts listCard to NULL. 
	*/
	Board();
	
	/** 
	* Create a board and initialize it with the pointer of listCard.  
	* @param std::list<Card> *listCard pointer of a list of cards.
	*/
	Board(std::list<iCard*> *listCard);
	
	/** 
	* Get the card which is at the Xth position.
	* @param unsigned int x position of the wanted card.
	* @return Card the pointer of the card.
	*/
	virtual iCard* getCardX(unsigned int x);
	
	/** 
	* Take the card which is at the Xth position and erase it of the deck.
	* @param unsigned int x position of the wanted card.
	* @return Card the pointer of the card.
	*/
	virtual iCard* takeCardX(unsigned int x);
	
	/**
	 * Delete the card which is at the Xth position.
	 * @param unsigned int x position of the card to be deleted.
	 */
	virtual void deleteCardX(unsigned int x);
	
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
 	* @param iCard* card pointer of the target card, unsigned int x wanted position.
 	*/
	virtual void addCardX(iCard* card,unsigned int x);
	
	/**
 	* Add a list of cards at the Xth position of a board.
 	* @param std::list<Card> *listCard pointer of the list of cards, unsigned int x wanted position. 
	 */
	virtual void addCardX(std::list<iCard*> *listcard, unsigned int x);
	
	/**
	 * Return true if the list is full (like an egg), else 0.
	 * @param std::list<Card> *listCard pointer of the list of cards.
	 * @return bool.
	 */
	bool isFull();
	
	/**
 	* Destructor.
 	*/
	virtual ~Board();

	std::list<iCard*>::iterator begin();

	std::list<iCard*>::iterator end() ;
};

#endif //BOARD_H
