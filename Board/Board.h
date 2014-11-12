#ifndef BOARD_H
#define BOARD_H


#include "Card.h"


class Board
{
public:
	Board();
	Board(std::list<Card> *listCard);
	
	Card * getCardX(unsigned int x);
	Card * takeCardX(unsigned int x);
	unsigned int getSize();
	unsigned int getMaxSize();
	void setMaxSize(unsigned int size);
	void addCardX(Card *card,unsigned int x);
	void addListCardX(std::list<Card> *listCard,unsigned int x);
	~Board();

private:
	std::list<*Card>	listCard;
};

#endif BOARD_H
