#include "Board.h"


Board::Board(){
  
  listCard = NULL;

}

Board::Board(std::list<Card*> listCard){
  
  this.listCard = listCard;

}

Card * Board::getCardX(unsigned int x){
  
  std::list<Card*>::iterator it;
  
  it = listCard.begin();
  it += x;
  
  return *it;  

}

Card * Board::takeCardX(unsigned int x){
  
  std::list<Card*>::iterator it;
  Card *card;
  
  it = listCard.begin();
  it += x;
  card = it;
  
  listcard.erase(it);
  
  return card;  
  
}

void Board::deleteCardX(unsigned int x){
  
  std::list<Card*>::iterator it;
  
  it = listCard.begin();
  it += x;
  
  listcard.erase(it);
  
  
}

unsigned int Board::getSize(){
  
  return listCard.size;
  
}

unsigned int Board::getMaxSize(){
  
  return listCard.max_size;
  
}

void Board::setMaxSize(unsigned int size){
  
  listCard.max_size = size;
  
}

void Board::addCardX(Card *card,unsigned int x){
  
  std::list<*Card>::iterator it;
  
  it = listCard.begin();
  it += x;
  insert(it, 1, *card);
  
}

void Board::addListCardX(std::list<Card*> listCard,unsigned int x){
  
  std::list<Card*>::iterator it;
  
  it = this.listCard.begin();
  it += x;
  
  this.listCard.splice(it,listeCard);
  
}

bool Board::isFull(std::list<Card*> listCard){
  
  if(listCard.size == listCar.max_size)
    return 1;
  else
    return 0;
  
}

Board::~Board();
