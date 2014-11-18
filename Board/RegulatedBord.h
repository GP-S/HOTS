#ifndef REGULATEDBOARD_H
#define REGULATEDBOARD_H

#include "Board.h"

/**
 * 
 * Write the functions in StackBoard.cpp, then write here the commentaries
 * 
 */


Class RegulatedBoard : public Board
{
public:
  
  Card * takeCardX(unsigned int x);
  void deletCardX(unsigned int x);
  void addCardX(Card *card,unsigned int x);
  void addListCardX(std::list<Card> *listCard,unsigned int x);
  ~StackBoard();
  
  
private: 
  std::list<*Card>	CardByArrivalTime;
};  


#endif REGULATEDBOARD_H
