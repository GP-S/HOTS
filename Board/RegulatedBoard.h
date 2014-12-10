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
  
	RegulatedBoard();
	RegulatedBoard(std::list<Card*> *listCard);
	Card* takeCardX(unsigned int x);
	void deletCardX(unsigned int x);
	void addCardX(Card *card,unsigned int x);
	~RegulatedBoard();
  
};  


#endif //REGULATEDBOARD_H
