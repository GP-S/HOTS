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
	unsigned int getLength();
	void addCardX(Card *card,unsigned int x);
	void addListCard(std::list<Card> *listCard);
	~Board();

private:
	std::list<Card>	listCard;
};

#endif // BOARD_H
