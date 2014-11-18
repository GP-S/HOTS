#ifndef BOARD_H
#define BOARD_H


#include "Card.h"

/**
* The class Board is .
* @author Nicolas Léger
* @author François Denquin
*/
class Board
{
public:
	
	/** 
	* Constructor which puts listCard to NULL. 
	*/
	Board();
	
	/** 
	* Create a board and initialize it with the pointer of listCard.  
	* @param std::list<Card> *listCard pointer of a list of card.
	*/
	Board(std::list<Card> *listCard);
	
	/** 
	* Get the card which is at the Xth position.
	* @param unsigned int x position of the wanted card.
	* @return Card the pointer of the card.
	*/
	virtual Card * getCardX(unsigned int x);
	
	/** 
	* Take the card which is at the Xth position and erase it of the deck.
	* @param unsigned int x position of the wanted card.
	* @return Card the pointer of the card.
	*/
	virtual Card * takeCardX(unsigned int x);
	
	/**
	 * Delete the card which is at the Xth position.
	 * @param unsigned int x position of the card to be deleted.
	 */
	virtual void deletCardX(unsigned int x);
	
	/** 
	* Return the size of the list.
	*/
	virtual unsigned int getSize();
	
	/** 
	* Return the maximum size of the list.  
	*/
	virtual unsigned int getMaxSize();
	
	/** 
	* Set the maximum size of the list to the value size.  
	* @param unsigned int size.
	*/
	virtual void setMaxSize(unsigned int size);
	
	/**
 	* Add a card at the Xth position of a board.
 	* @param Card *card pointer of the target card, unsigned int x wanted position.
 	*/
	virtual void addCardX(Card *card,unsigned int x);
	
	/**
 	* Add a list of cards at the Xth position of a board.
 	* @param std::list<Card> *listCard pointer of the list of cards, unsigned int x wanted position. 
	 */
	virtual void addListCardX(std::list<Card> *listCard,unsigned int x);
	
	/**
 	* Destructor.
 	*/
	virtual ~Board();

private:
	std::list<*Card>	listCard;
};

#endif BOARD_H
