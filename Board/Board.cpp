#include "Board.h"





Board::Borad(){
  
  listCard = NULL;

  
}


Board::Borad(std::list<Card> *listCard){
  
  this.listCard = listCard;

  
}


Card Board::getCardX(unsigned int x){
  
  std::list<Card>::iterator it;
  
  it = listCard.begin();
  it += x;
  
  return it;  

}



Card * takeCardX(unsigned int x){
  
  std::list<Card>::iterator it;
  
  it = listCard.begin();
  it += x;
  
  Card card = it;
  
  listcard.erase(it);
  
  return *card;  
  
}



unsigned int getSize(){
  
  return listCard.size;
  
}

unsigned int getMaxSize(){
  
  return listCard.max_size;
  
}

void setMaxSize(unsigned int size){
  
  listCard.max_size = size;
  
}


void addCardX(Card *card,unsigned int x){
  
  std::list<Card>::iterator it;
  
  it = listCard.begin();
  it += x;
  insert(it, 1, *card);
  
}



void addListCardX(std::list<Card> *listCard,unsigned int x){
  
  std::list<Card>::iterator it;
  
  it = this.listCard.begin();
  it += x;
  
  this.listCard.splice(it,listeCard);
  
}



~Board();



























