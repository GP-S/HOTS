#ifndef STACKBOARD_H
#define STACKBOARD_H

#include "Board.h"


/**
 * 
 * Write the functions in StackBoard.cpp, then write here the commentaries
 * 
 */
Class StackBoard : public Board
{
public:

  Card * takeCardX(unsigned int x);
  void deletCardX(unsigned int x);
  void addCardX(Card *card,unsigned int x);
  void addListCardX(std::list<Card> *listCard,unsigned int x);
  ~StackBoard();

private:

};

#endif STACKBOARD_H
