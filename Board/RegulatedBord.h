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
  ~StackBoard();
  
  
protected: 
  std::list<*Card>	CardByArrivalTime;
};  


#endif REGULATEDBOARD_H
