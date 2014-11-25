#ifndef IBOARD_H
#define IBOARD_H


#include "Card.h"

/**
* The class iBoard is .
* @author Nicolas Léger
* @author François Denquin
*/
class iBoard
{
public:
	
	iBoard() = 0;
	
	virtual iBoard(std::list<Card> *listCard) = 0;
	
	virtual Card * getCardX(unsigned int x) = 0;
	
	virtual Card * takeCardX(unsigned int x) = 0;
	
	virtual void deletCardX(unsigned int x) = 0;
	
	virtual unsigned int getSize() = 0;
	
	virtualunsigned int getMaxSize() = 0;
	
	virtual void setMaxSize(unsigned int size) = 0;

	virtual void addCardX(Card *card,unsigned int x) = 0;

	virtual void addListCardX(std::list<Card> *listCard,unsigned int x) = 0;
	
	virtual bool isFull(std::list<Card> *listCard) = 0;

	virtual ~iBoard() = 0;

protected:
	std::list<*Card>	listCard;
};

#endif IBOARD_H
