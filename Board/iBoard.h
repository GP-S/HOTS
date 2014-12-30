#ifndef IBOARD_H
#define IBOARD_H


#include "iCard.h"

/**
* The class iBoard is .
* @author Nicolas Léger
* @author François Denquin
*/
class iBoard
{
public:
	
	/** 
	* Get the card which is at the Xth position.
	* @param unsigned int x position of the wanted card.
	* @return Card the pointer of the card.
	*/
	virtual iCard * getCardX(unsigned int x) = 0;
	
	/** 
	* Take the card which is at the Xth position and erase it of the deck.
	* @param unsigned int x position of the wanted card.
	* @return Card the pointer of the card.
	*/
	virtual iCard * takeCardX(unsigned int x) = 0;
	
	/**
	 * Delete the card which is at the Xth position.
	 * @param unsigned int x position of the card to be deleted.
	 */
	virtual void deleteCardX(unsigned int x) = 0;
	
	/** 
	* Return the size of the list.
	* @return unsigned int the size.
	*/
	virtual unsigned int getSize() = 0;
	
	/** 
	* Return the maximum size of the list.  
	* @return unsigned int the maximum size.
	*/
	virtual unsigned int getMaxSize() = 0;
	
	/** 
	* Set the maximum size of the list to the value size.  
	* @param unsigned int size.
	*/
	virtual void setMaxSize(unsigned int size) = 0;

	/**
 	* Add a card at the Xth position of a board.
 	* @param Card *card pointer of the target card, unsigned int x wanted position.
 	*/
	virtual void addCardX(iCard *card,unsigned int x) = 0;

	/**
 	* Add a list of cards at the Xth position of a board.
 	* @param std::list<iCard> *listCard pointer of the list of cards, unsigned int x wanted position. 
	 */
	virtual void addListCardX(std::list<iCard*> *listCard,unsigned int x) = 0;
	
	/**
	 * Return true if the list is full (like an egg), else 0.
	 * @param std::list<iCard> *listCard pointer of the list of cards.
	 * @return bool.
	 */
	virtual bool isFull() = 0;

	/**
	 * Return the position in the CardArrivalByTime listCard.
	 * @param iCard *card pointer of card.
	 * @return unsigned int.
	 */
	virtual unsigned int CardArrivalByTime(iCard *card) = 0;

	/**
 	* Destructor.
 	*/
	virtual ~iBoard() = 0;

	virtual std::list<iCard*>::iterator begin() = 0;

	virtual std::list<iCard*>::iterator end() = 0;


};

#endif //IBOARD_H